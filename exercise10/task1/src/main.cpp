#include <iostream>
#include <string>
#include "compiler.h"

int main(int argc, char const *argv[]) {
  std::string source_code(std::istreambuf_iterator<char>(std::cin), {});

  auto bytecode = compiler::lex(source_code);

  for (auto line : bytecode) {
    for (auto token : line) {
      std::cout << token.value << " ";
    }

    std::cout << std::endl;
  }

  return 0;
}
