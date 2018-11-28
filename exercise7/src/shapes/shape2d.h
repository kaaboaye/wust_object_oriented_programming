#ifndef SHAPES_SHAPE2D_H
#define SHAPES_SHAPE2D_H

namespace shapes {
class Shape2d {
 public:
  virtual double area() const = 0;
};
}  // namespace shapes

#endif