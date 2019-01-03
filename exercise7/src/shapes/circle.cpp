#include "circle.h"

namespace shapes {
Circle::Circle(Shape2d::Position position, double ray) : Shape2d(position) {
  this->ray = ray;
}

double Circle::area() const { return 3.14 * ray * ray; }
}  // namespace shapes