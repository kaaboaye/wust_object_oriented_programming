#ifndef SHAPES_SHAPE_3D
#define SHAPES_SHAPE_3D

#include "shape2d.h"

namespace shapes {
class Shape3d : public Shape2d {
 public:
  virtual double volume() const = 0;
};
}  // namespace shapes

#endif