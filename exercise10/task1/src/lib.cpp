#include "lib.h"

namespace lib {
AssertNeverException::AssertNeverException(const std::string& message)
    : message(message){};

void assert_never(std::string message) {
  throw new AssertNeverException(message);
}
}  // namespace lib