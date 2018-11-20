#ifndef VECTOR_CLI_COMMANDS_H
#define VECTOR_CLI_COMMANDS_H

#include <string>

namespace vector {
namespace CliCommands {
enum t {
  v1,
  v2,
  dot_product,
  help,
  exit,
  undefined,
};

t parse(const std::string &str);
}  // namespace CliCommands
}  // namespace vector

#endif