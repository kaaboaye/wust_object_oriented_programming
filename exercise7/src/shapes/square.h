#ifndef SHAPES_SQUARE_H
#define SHAPES_SQUARE_H

#include "shape2d.h"

namespace shapes {
class Square : public Shape2d {
  double length;

 public:
  Square(Shape2d::Position position, double length);
  double area() const override;
};
}  // namespace shapes

#endif