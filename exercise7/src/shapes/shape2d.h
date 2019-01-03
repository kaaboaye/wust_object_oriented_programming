#ifndef SHAPES_SHAPE2D_H
#define SHAPES_SHAPE2D_H

#include <string>

namespace shapes {
class Shape2d {
 public:
  struct Position {
    double x;
    double y;
  };

 private:
  Position position;

 public:
  Shape2d(Position position);
  virtual double area() const = 0;
  std::string position_to_string() const;
};
}  // namespace shapes

#endif