#ifndef SHAPES_CUBOID_H
#define SHAPES_CUBOID_H

#include "rectangle.h"

namespace Shapes
{
class Cuboid : Rectangle
{
  double _h;

public:
  Cuboid();
  Cuboid(double a, double b, double h);

  double volume() const;
  double diagonal() const;
};
} // namespace Shapes

#endif