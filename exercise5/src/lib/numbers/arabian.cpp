#include "arabian.h"

namespace Numbers
{
Arabian::Arabian()
{
  _num = 0;
}

Arabian::Arabian(int64_t num)
{
  _num = num;
}

std::string Arabian::to_string() const
{
  return std::to_string(_num);
}
} // namespace Numbers