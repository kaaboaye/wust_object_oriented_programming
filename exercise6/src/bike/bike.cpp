#include "bike.h"
#include <stdio.h>

namespace bike {
Bike::Bike() {
  puts("na pewno rower");
  Bike::exists = true;
}

bool Bike::functional() {
  return Bike::exists && Pedal::exists && Wheel::functional();
}
}  // namespace bike
