#include "amphibian.h"

namespace vehicle {
const char *Amphibian::driving_sound() { return Car::sound(); }
const char *Amphibian::floating_sound() { return Boat::sound(); }

}  // namespace vehicle
