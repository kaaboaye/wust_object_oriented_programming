#include "compiler.h"
#include <algorithm>
#include "stack.hh"
#include "symbol.h"

namespace compiler {

bytecode_t lex(std::string source_code) {
  lexertk::generator generator;

  if (!generator.process(source_code)) {
    throw "Failed to lex";
  }

  // meke it cpp-able
  line_t tokens;
  for (std::size_t i = 0; i < generator.size(); ++i) {
    tokens.push_back(generator[i]);
  }

  bytecode_t lines;

  {
    std::vector<lexertk::token> line;
    for (auto &t : tokens) {
      if (t.type == lexertk::token::e_eof) {
        lines.push_back(line);
        line.clear();
      } else {
        line.push_back(t);
      }
    }
  }

  return lines;
}

bytecode_t compile(const bytecode_t &bytecode) {
  std::transform(bytecode.begin(), bytecode.end(), bytecode.begin(),
                 compile_line);
  return bytecode;
}

line_t compile_line(line_t line) {
  Stack<lexertk::token> stack;
  line_t out;

  for (auto token : line) {
    switch (token.type) {
      case lexertk::token::e_number:
        out.push_back(token);
        break;

      case lexertk::token::e_add:
      case lexertk::token::e_sub:
      case lexertk::token::e_mul:
      case lexertk::token::e_div:
      case lexertk::token::e_lbracket:
        stack.push(token);
        break;

      case lexertk::token::e_rbracket:
        for (auto [is_ok, stack_token] = stack.pop();
             is_ok == symbol::ok &&
             stack_token.type != lexertk::token::e_lbracket;
             std::tie(is_ok, stack_token) = stack.pop()) {
          out.push_back(stack_token);
        }
        break;
    }
  }
}

}  // namespace compiler