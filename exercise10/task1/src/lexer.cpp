#include "lexer.h"
#include "compiler.h"

namespace lexer {

compiler::bytecode_t lex(std::string source_code) {
  lexertk::generator generator;

  if (!generator.process(source_code)) {
    throw "Failed to lex";
  }

  compiler::bytecode_t lines;

  // split lines
  std::deque<compiler::token_t> line;
  for (std::size_t i = 0; i < generator.size(); ++i) {
    const auto t = generator[i];
    if (t.type == compiler::token_t::e_eof) {
      lines.push_back(line);
      line.clear();
    } else {
      line.push_back(t);
    }
  }

  return lines;
}
}  // namespace lexer

// 12 + a * (b * c + d / e)
// 12 + 1 * (2 * 3 + 4 / 5)

// 12 a b c * d e / + * +
// 12 1 2 3 * 4 5 / + * +