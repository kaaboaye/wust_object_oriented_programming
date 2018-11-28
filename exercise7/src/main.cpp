#include <iostream>

#include "shapes/circle.h"
#include "shapes/rectangle.h"
#include "shapes/square.h"
#include "shapes/triangle.h"

using namespace shapes;
using namespace std;

int main() {
  Circle c(4);
  Rectangle r(2, 3);
  Square s(4);
  Triangle t(3, 4, 5);

  cout << "Areas" << endl
       << "Circle " << c.area() << endl
       << "Rectangle " << r.area() << endl
       << "Square " << s.area() << endl
       << "Triangle " << t.area() << endl;

  return 0;
}