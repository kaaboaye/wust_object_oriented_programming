#ifndef SHAPES_RECTANGLE_H
#define SHAPES_RECTANGLE_H

namespace Shapes
{
class Rectangle
{
  double _a;
  double _b;

public:
  Rectangle();
  Rectangle(double _a, double _b);

  double area() const;
  double diagonal() const;
};
} // namespace Shapes

#endif