#include <sstream>
#include <string>

#include "shape2d.h"

namespace shapes {
Shape2d::Shape2d(Shape2d::Position position) { this->position = position; }

std::string Shape2d::position_to_string() const {
  std::stringstream ss;
  ss << "(" << position.x << ", " << position.y << ")";
  return ss.str();
}
}  // namespace shapes