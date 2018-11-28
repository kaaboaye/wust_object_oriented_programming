#include <math.h>

#include "triangle.h"

namespace shapes {
Triangle::Triangle(double a, double b, double c) {
  this->a = a;
  this->b = b;
  this->c = c;
}

double Triangle::area() const {
  double p = (a + b + c) / 2;
  return sqrt(p * (p - a) * (p - b) * (p - c));
}
}  // namespace shapes