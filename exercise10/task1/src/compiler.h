#ifndef COMPILER_H
#define COMPILER_H

#include <deque>
#include <string>
#include <tuple>
#include "../lexertk/lexertk.hpp"
#include "lib.h"

namespace compiler {

typedef lexertk::token token_t;
typedef std::deque<token_t> line_t;
typedef std::deque<line_t> bytecode_t;

std::tuple<std::deque<symbol::t>, bytecode_t> compile(std::string source_code);
}  // namespace compiler

#endif