#include <iostream>
#include <string>

#include "compiler.h"
#include "lib.h"
#include "runtime.h"

int main(int argc, char const* argv[]) {
  try {
    std::string source_code(std::istreambuf_iterator<char>(std::cin), {});

    auto [errors, bytecode] = compiler::compile(source_code);

    if (errors.size() != 0) {
      std::cout << "jebło" << std::endl;
      return 1;
    }

    for (const auto& line : bytecode) {
      for (const auto& token : line) {
        std::cout << token.value << " ";
      }

      std::cout << std::endl;
    }

    runtime::run(bytecode);
  } catch (lib::AssertNeverException* err) {
    std::cout << err->message << std::endl;
  }

  return 0;
}
