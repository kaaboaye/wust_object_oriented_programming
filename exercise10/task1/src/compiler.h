#ifndef COMPILER_H
#define COMPILER_H

#include <string>
#include <vector>
#include "../lexertk/lexertk.hpp"

namespace compiler {

typedef std::vector<lexertk::token> line_t;
typedef std::vector<line_t> bytecode_t;
bytecode_t lex(std::string source);
bytecode_t compile(std::string source);
line_t compile_line(line_t line);
}  // namespace compiler

#endif