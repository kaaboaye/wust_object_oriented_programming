#include "pedal.h"
#include <stdio.h>
namespace bike {
Pedal::Pedal() {
  puts("pedal");
  Pedal::exists = true;
}
}  // namespace bike
