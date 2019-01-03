#include "rectangle.h"

namespace shapes {
Rectangle::Rectangle(Shape2d::Position position, double length, double height)
    : Shape2d(position) {
  this->length = length;
  this->height = height;
}

double Rectangle::area() const { return length * height; }
}  // namespace shapes