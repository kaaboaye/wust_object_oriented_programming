#include "bike.h"

namespace bike {
Bike::Bike() { Bike::exists = true; }

bool Bike::functional() {
  return Bike::exists && Pedal::exists && Wheel::functional();
}
}  // namespace bike
