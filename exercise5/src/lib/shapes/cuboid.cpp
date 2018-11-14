#include <cmath>

#include "cuboid.h"

namespace Shapes
{
Cuboid::Cuboid() : Rectangle()
{
  _h = 0;
}

Cuboid::Cuboid(double a, double b, double h) : Rectangle(a, b)
{
  _h = h;
}

double Cuboid::volume() const
{
  return Rectangle::area() * _h;
}

double Cuboid::diagonal() const
{
  double d = Rectangle::diagonal();

  return sqrt(d * d + _h * _h);
}

} // namespace Shapes