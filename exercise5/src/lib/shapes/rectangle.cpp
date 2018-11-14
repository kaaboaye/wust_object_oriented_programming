#include <cmath>

#include "rectangle.h"

namespace Shapes
{
Rectangle::Rectangle()
{
  _a = 0.0;
  _b = 0.0;
}

Rectangle::Rectangle(double a, double b)
{
  _a = a;
  _b = b;
}

double Rectangle::area() const
{
  return _a * _b;
}

double Rectangle::diagonal() const
{
  return sqrt(_a * _a + _b * _b);
}

} // namespace Shapes