#ifndef NUMBERS_ROMAN_H
#define NUMBERS_ROMAN_H

#include <string>
#include <stdint.h>

#include "arabian.h"

namespace Numbers
{
class Roman : Arabian
{
public:
  Roman();
  Roman(int64_t num);
  std::string to_string() const;
};
} // namespace Numbers

#endif