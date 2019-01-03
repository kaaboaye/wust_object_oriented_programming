#ifndef SHAPES_CIRCLE_H
#define SHAPES_CIRCLE_H

#include "shape2d.h"

namespace shapes {
class Circle : public Shape2d {
  double ray;

 public:
  Circle(Shape2d::Position position, double ray);
  double area() const override;
};
}  // namespace shapes

#endif