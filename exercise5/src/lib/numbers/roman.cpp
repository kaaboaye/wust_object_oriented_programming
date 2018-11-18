#include "roman.h"

namespace Numbers {
Roman::Roman() : Arabian() {}
Roman::Roman(int64_t num) : Arabian(num) {}

std::string Roman::to_string() const {
  static const std::string M[] = {"", "M", "MM", "MMM"};
  static const std::string C[] = {"",  "C",  "CC",  "CCC",  "CD",
                                  "D", "DC", "DCC", "DCCC", "CM"};
  static const std::string X[] = {"",  "X",  "XX",  "XXX",  "XL",
                                  "L", "LX", "LXX", "LXXX", "XC"};
  static const std::string I[] = {"",  "I",  "II",  "III",  "IV",
                                  "V", "VI", "VII", "VIII", "IX"};

  return M[_num / 1000] + C[(_num % 1000) / 100] + X[(_num % 100) / 10] +
         I[(_num % 10)];
}
}  // namespace Numbers
