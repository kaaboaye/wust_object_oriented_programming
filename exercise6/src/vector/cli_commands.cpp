#include <unordered_map>

#include "cli_commands.h"

namespace vector {
namespace CliCommands {

t parse(const std::string &str) {
  static const std::unordered_map<std::string, t> map = {
      {"v1", v1},     {"v2", v2},     {"dot_product", dot_product},
      {"help", help}, {"exit", exit},
  };

  auto it = map.find(str);
  return it != map.end() ? it->second : undefined;
}

}  // namespace CliCommands
}  // namespace vector