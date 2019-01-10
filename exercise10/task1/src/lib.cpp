#include "lib.h"

namespace lib {
void assert_never() { throw new AssertNeverException(); }
}  // namespace lib