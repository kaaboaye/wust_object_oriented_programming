#include "circle.h"

namespace shapes {
Circle::Circle(double ray) { this->ray = ray; }

double Circle::area() const { return 3.14 * ray * ray; }
}  // namespace shapes