#ifndef BIKE_BIKE_H
#define BIKE_BIKE_H

#include "pedal.h"
#include "wheel.h"

namespace bike {
class Bike : Wheel, Pedal {
 public:
  bool exists;

  Bike();
  bool functional();
};
}  // namespace bike

#endif
