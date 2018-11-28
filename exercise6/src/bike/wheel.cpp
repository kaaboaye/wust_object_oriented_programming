#include "wheel.h"
#include <stdio.h>

namespace bike {
Wheel::Wheel() {
  puts("wheel");
  Wheel::exists = true;
}

bool Wheel::functional() { return Wheel::exists && Tyre::exists; }
}  // namespace bike
