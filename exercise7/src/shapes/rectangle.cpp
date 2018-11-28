#include "rectangle.h"

namespace shapes {
Rectangle::Rectangle(double length, double height) {
  this->length = length;
  this->height = height;
}

double Rectangle::area() const { return length * height; }
}  // namespace shapes