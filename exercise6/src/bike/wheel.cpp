#include "wheel.h"

namespace bike {
Wheel::Wheel() { Wheel::exists = true; }

bool Wheel::functional() { return Wheel::exists && Tyre::exists; }
}  // namespace bike
