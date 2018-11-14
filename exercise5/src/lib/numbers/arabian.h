#ifndef NUMBERS_ARABIAN_H
#define NUMBERS_ARABIAN_H

#include <stdint.h>
#include <string>

namespace Numbers
{
class Arabian
{
protected:
  int64_t _num;

public:
  Arabian();
  Arabian(int64_t num);
  std::string to_string() const;
};
} // namespace Numbers

#endif