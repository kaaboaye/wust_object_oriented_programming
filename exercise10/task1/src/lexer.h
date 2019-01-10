#ifndef LEXER_H
#define LEXER_H

#include <deque>
#include <tuple>
#include "../lexertk/lexertk.hpp"
#include "compiler.h"
#include "lib.h"

namespace lexer {
compiler::bytecode_t lex(std::string source);
}  // namespace lexer

#endif