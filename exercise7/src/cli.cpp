#include <iostream>

#include "cli.h"
#include "shapes/circle.h"
#include "shapes/rectangle.h"
#include "shapes/shape2d.h"
#include "shapes/square.h"
#include "shapes/triangle.h"

namespace cli {
namespace opt {
enum t {
  circle,
  rectangle,
  square,
  triangle,
};
}

void main() {
  for (;;) {
    std::cout << std::endl
              << "Shapes:" << std::endl
              << "\t" << opt::circle << ": circle" << std::endl
              << "\t" << opt::rectangle << ": rectangle" << std::endl
              << "\t" << opt::square << ": square" << std::endl
              << "\t" << opt::triangle << ": triangle" << std::endl
              << "Provide shape: ";

    int int_shape;
    std::cin >> int_shape;
    opt::t shape = (opt::t)int_shape;

    shapes::Shape2d::Position position;
    {
      double x, y;
      std::cout << "Provide position: ";
      std::cin >> x >> y;
      position = {x, y};
    }

    switch (shape) {
      case opt::circle: {
        std ::cout << "Provide ray: ";
        double ray;
        std::cin >> ray;
        shapes::Circle circle(position, ray);
        std::cout << "Circle at position " << circle.position_to_string()
                  << " with area " << circle.area() << std::endl;
        break;
      }

      case opt::rectangle: {
        std::cout << "Provide length and height: ";
        double l, h;
        std::cin >> l >> h;
        shapes::Rectangle rectangle(position, l, h);
        std::cout << "Rectangle at position " << rectangle.position_to_string()
                  << " with area " << rectangle.area() << std::endl;
        break;
      }

      case opt::square: {
        std::cout << "Provide length: ";
        double length;
        std::cin >> length;
        shapes::Square square(position, length);
        std::cout << "Square at position " << square.position_to_string()
                  << " with area " << square.area() << std::endl;
        break;
      }

      case opt::triangle: {
        std::cout << "Provide sides: ";
        double a, b, c;
        std::cin >> a >> b >> c;
        shapes::Triangle triangle(position, a, b, c);
        std::cout << "Triangle at position " << triangle.position_to_string()
                  << " with area " << triangle.area() << std::endl;
        break;
      }

      default: {
        std::cout << "Dzban." << std::endl;
        break;
      }
    }
  }
}
}  // namespace cli