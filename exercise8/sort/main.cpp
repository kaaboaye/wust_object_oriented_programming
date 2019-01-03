#include <stdio.h>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

template <typename T>
void sort(std::vector<T> vec, bool &cmp(T, T)) {
  std::sort(vec.begin(), vec.end(), cmp);
}

struct Point {
  double x;
  double y;

  std::string to_string() {
    std::stringstream ss;
    ss << "(" << x << ", " << y << ")";
    return ss.str();
  }
};

int main() {
  std::vector<Point> points = {
      {2, 1},
      {3, 3},
      {1, 2},
  };

  puts("original");

  for (int i = 0; i < points.size(); ++i) {
    puts(points[i].to_string().c_str());
  }

  puts("\nby x");

  sort<Point>(points, [](Point a, Point b) { return a.x > b.x; });

  for (int i = 0; i < points.size(); ++i) {
    puts(points[i].to_string().c_str());
  }

  puts("\nby y");

  std::sort(points.begin(), points.end(),
            [](Point a, Point b) { return a.y > b.y; });

  for (int i = 0; i < points.size(); ++i) {
    puts(points[i].to_string().c_str());
  }

  return 0;
}
