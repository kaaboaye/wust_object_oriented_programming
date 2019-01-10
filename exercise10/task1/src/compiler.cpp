#include <algorithm>
#include <tuple>

#include "compiler.h"
#include "lexer.h"
#include "lib.h"
#include "stack.hh"

namespace compiler {

std::tuple<symbol::t, line_t> compile_line(line_t line);

typedef std::deque<std::tuple<symbol::t, line_t>>
    compiled_lines_with_statuses_t;

std::tuple<std::deque<symbol::t>, bytecode_t> compile(std::string source_code) {
  const auto lexcode = lexer::lex(source_code);

  const auto compiled_lines_with_statuses =
      lib::map<bytecode_t, compiled_lines_with_statuses_t>(lexcode,
                                                           compile_line);

  const auto broken_lines =
      lib::filter(compiled_lines_with_statuses,
                  [](const std::tuple<symbol::t, line_t> &tuple) {
                    auto [status, _line] = tuple;
                    return status != symbol::ok;
                  });

  const auto errors =
      lib::map<compiled_lines_with_statuses_t, std::deque<symbol::t>>(
          broken_lines, [](const std::tuple<symbol::t, line_t> &tuple) {
            auto [status, _line] = tuple;
            return status;
          });

  const auto bytecode = lib::map<compiled_lines_with_statuses_t, bytecode_t>(
      compiled_lines_with_statuses,
      [](const std::tuple<symbol::t, line_t> &tuple) {
        auto [_status, line] = tuple;
        return line;
      });

  return std::make_tuple(errors, bytecode);
}

std::tuple<symbol::t, line_t> compile_line(line_t line) {
  lib::stack<token_t> stack;
  line_t out;

  for (auto token : line) {
    switch (token.type) {
      case token_t::e_number:
      case token_t::e_symbol:
        out.push_back(token);
        break;

      case token_t::e_add:
      case token_t::e_sub:
      case token_t::e_mul:
      case token_t::e_div:
      case token_t::e_pow:
      case token_t::e_lbracket:
        stack.push(token);
        break;

      case token_t::e_rbracket: {
        symbol::t status;
        token_t stack_token;

        for (;;) {
          std::tie(status, stack_token) = stack.pop();

          if (status == symbol::empty) {
            return std::make_tuple(symbol::brackets_error, out);
          }

          if (stack_token.type == token_t::e_lbracket) {
            break;
          }

          if (status == symbol::ok) {
            out.push_back(token);
            continue;
          }

          lib::assert_never("error during bracket compilation");
        }
        break;
      }

      default:
        lib::assert_never("unexpected token");
        break;
    }
  }

  for (auto [status, stack_item] = stack.pop(); status == symbol::ok;
       std::tie(status, stack_item) = stack.pop()) {
    out.push_back(stack_item);
  }

  return std::make_tuple(symbol::ok, out);
}

}  // namespace compiler
