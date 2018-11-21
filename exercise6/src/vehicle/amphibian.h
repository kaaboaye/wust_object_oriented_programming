#ifndef VEHICLE_AMPHIBIAN_H
#define VEHICLE_AMPHIBIAN_H

#include "boat.h"
#include "car.h"

namespace vehicle {
class Amphibian : public Car, public Boat {
 public:
  const char *driving_sound();
  const char *floating_sound();
};
}  // namespace vehicle

#endif
