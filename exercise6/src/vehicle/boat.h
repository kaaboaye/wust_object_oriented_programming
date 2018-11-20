#ifndef VEHICLE_BOAT_H
#define VEHICLE_BOAT_H

#include "vehicle.h"

namespace vehicle {
class Boat : virtual public Vehicle {
 public:
  const char* sound() override;
};
}  // namespace vehicle

#endif
