#include <iostream>
#include <string>

#include "cli.h"
#include "cli_commands.h"
#include "spare_vector.h"

namespace vector {

static void help() {
  std::cout << "vector commands" << std::endl
            << "v1 1 2 … 4 end" << std::endl
            << "v2 1 2 … 4 end" << std::endl
            << "dot_product" << std::endl
            << "help" << std::endl
            << "exit" << std::endl;
}

static SpareVector* read_vector() {
  // std::string entry;
  // SpareVector* vec = new SpareVector();

  // for (std::cin >> entry; entry != "end"; std::cin >> entry) {
  //   vec->push(std::stol(entry));
  // }

  // return vec;
}

void main() {
  std::string s_cmd;
  SpareVector* v1 = nullptr;
  SpareVector* v2 = nullptr;

  for (;;) {
    std::cin >> s_cmd;
    CliCommands::t cmd = CliCommands::parse(s_cmd);

    switch (cmd) {
      case CliCommands::v1:
        if (v1) {
          delete v1;
        }

        v1 = read_vector();
        break;

      case CliCommands::v2:
        if (v2) {
          delete v2;
        }

        v2 = read_vector();
        break;

      case CliCommands::dot_product:
        std::cout << SpareVector::dot_product(*v1, *v2);
        break;

      case CliCommands::help:
        help();
        break;

      case CliCommands::exit:
        return;

      case CliCommands::undefined:
        std::cout << "bad command ~~grr~~" << std::endl;
        break;
    }
  }
}
}  // namespace vector