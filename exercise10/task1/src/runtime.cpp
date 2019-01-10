#include <cmath>
#include <functional>
#include <iostream>
#include <sstream>
#include <string>

#include "lib.h"
#include "runtime.h"
#include "stack.hh"

namespace runtime {
typedef double number_t;
void run_line(compiler::line_t line);
compiler::token_t evaluate(compiler::token_t a, compiler::token_t b,
                           compiler::token_t op);
number_t token_to_number(compiler::token_t token);
compiler::token_t number_to_token(number_t num);

void run(compiler::bytecode_t bytecode) { lib::each(bytecode, run_line); }

void run_line(compiler::line_t line) {
  lib::stack<compiler::token_t> stack;

  for (const auto& token : line) {
    switch (token.type) {
      case compiler::token_t::e_number:
      case compiler::token_t::e_symbol:
        stack.push(token);
        break;

      case compiler::token_t::e_add:
      case compiler::token_t::e_sub:
      case compiler::token_t::e_mul:
      case compiler::token_t::e_div:
      case compiler::token_t::e_pow: {
        auto [is_a, a] = stack.pop();
        auto [is_b, b] = stack.pop();

        if (is_a != symbol::ok || is_b != symbol::ok) {
          lib::assert_never("runtime error / bad equation");
        }

        stack.push(evaluate(a, b, token));
        break;
      }

      default:
        break;
    }
  }

  const auto [is_result, result] = stack.pop();
  if (is_result != symbol::ok) {
    lib::assert_never("wtf no result?");
  }

  std::cout << result.value << std::endl;

  const auto [is_something_else, nothing] = stack.pop();
  if (is_result == symbol::ok) {
    std::cout << nothing.value << " : " << lexertk::token::to_str(nothing.type)
              << std::endl;
    lib::assert_never("something is on stack :O ");
  }
}

compiler::token_t evaluate(compiler::token_t token_a, compiler::token_t token_b,
                           compiler::token_t op) {
  auto a = token_to_number(token_a);
  auto b = token_to_number(token_b);

  switch (op.type) {
    case compiler::token_t::e_add:
      return number_to_token(a + b);

    case compiler::token_t::e_sub:
      return number_to_token(a - b);

    case compiler::token_t::e_mul:
      return number_to_token(a * b);

    case compiler::token_t::e_div:
      return number_to_token(a / b);

    case compiler::token_t::e_pow:
      return number_to_token(pow(b, a));

    default:
      lib::assert_never("wtf this should never happen");
      return compiler::token_t();
  }
}

number_t token_to_number(compiler::token_t token) {
  if (token.type != compiler::token_t::e_number) {
    lib::assert_never("token not a number");
  }

  number_t number;

  std::stringstream ss;
  ss << token.value;
  ss >> number;
  return number;
}

compiler::token_t number_to_token(number_t num) {
  compiler::token_t t;

  std::stringstream ss;
  ss << num;

  t.type = compiler::token_t::e_number;
  t.value = ss.str();
  t.position = 0;

  return t;
}

}  // namespace runtime