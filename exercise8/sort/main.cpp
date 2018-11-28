#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string>

template <typename T>
void sort(T *arr, size_t n, int cmp(const T *, const T *)) {
  qsort(arr, n, sizeof(T), (int (*_Nonnull)(const void *, const void *))cmp);
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
  Point points[] = {
      {2, 1},
      {3, 3},
      {1, 3},
  };
  size_t points_n = 3;

  puts("original");

  for (int i = 0; i < points_n; ++i) {
    puts(points[i].to_string().c_str());
  }

  puts("\nby x");

  sort<Point>(points, points_n, [](const Point *a, const Point *b) {
    return (int)(a->x - b->x);
  });

  for (int i = 0; i < points_n; ++i) {
    puts(points[i].to_string().c_str());
  }

  puts("\nby y");

  sort<Point>(points, points_n, [](const Point *a, const Point *b) {
    return (int)(a->y - b->y);
  });

  for (int i = 0; i < points_n; ++i) {
    puts(points[i].to_string().c_str());
  }

  return 0;
}
