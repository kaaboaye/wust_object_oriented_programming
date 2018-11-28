#ifndef SHAPES_RECTANGLE_H
#define SHAPES_RECTANGLE_H

#include "shape2d.h"

namespace shapes {
class Rectangle : public Shape2d {
  double length;
  double height;

 public:
  Rectangle(double length, double height);
  double area() const override;
};
}  // namespace shapes

#endif