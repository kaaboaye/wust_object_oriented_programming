#include "square.h"

namespace shapes {
Square::Square(double length) { this->length = length; }
double Square::area() const { return length * length; }
}  // namespace shapes