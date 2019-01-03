#include "square.h"

namespace shapes {
Square::Square(Shape2d::Position position, double length) : Shape2d(position) {
  this->length = length;
}
double Square::area() const { return length * length; }
}  // namespace shapes