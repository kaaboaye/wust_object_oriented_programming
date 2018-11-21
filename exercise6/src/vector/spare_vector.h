#ifndef VECTOR_SPARE_VECTOR_H
#define VECTOR_SPARE_VECTOR_H

#include <stdint.h>
#include <string>
#include <tuple>
#include <vector>

namespace vector {
class SpareVector {
 public:
  static std::tuple<std::string, int64_t> dot_product(SpareVector *v1,
                                                      SpareVector *v2);

 private:
  std::vector<bool> order;
  std::vector<int64_t> values;

 public:
  void push(int64_t);
};
}  // namespace vector
#endif
