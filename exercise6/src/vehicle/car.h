#ifndef VEHICLE_CAR_H
#define VEHICLE_CAR_H

#include "vehicle.h"

namespace vehicle {
class Car : virtual public Vehicle {
 public:
  const char *sound();
};
}  // namespace vehicle

#endif
