#include <math.h>

#include "triangle.h"

namespace shapes {
Triangle::Triangle(Shape2d::Position position, double a, double b, double c)
    : Shape2d(position) {
  this->a = a;
  this->b = b;
  this->c = c;
}

double Triangle::area() const {
  double p = (a + b + c) / 2;
  return sqrt(p * (p - a) * (p - b) * (p - c));
}
}  // namespace shapes