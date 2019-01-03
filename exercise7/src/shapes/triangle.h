#ifndef SHAPES_TRIANGLE_H
#define SHAPES_TRIANGLE_H

#include "shape2d.h"

namespace shapes {
class Triangle : public Shape2d {
  double a;
  double b;
  double c;

 public:
  Triangle(Shape2d::Position position, double a, double b, double c);
  double area() const override;
};
}  // namespace shapes

#endif