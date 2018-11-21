#ifndef BIKE_WHEEL_H
#define BIKE_WHEEL_H

#include "tyre.h"

namespace bike {
class Wheel : Tyre {
 public:
  bool exists;

  Wheel();
  bool functional();
};
}  // namespace bike

#endif
