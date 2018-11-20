#include <algorithm>

#include "spare_vector.h"

namespace vector {

int64_t SpareVector::dot_product(SpareVector &v1, SpareVector &v2) {
  auto order1 = v1.order.begin();
  auto values1 = v1.order.begin();

  auto order2 = v2.order.begin();
  auto values2 = v2.values.begin();

  int64_t accumulator = 0;

  for (; order1 != v1.order.end() && order2 != v2.order.end();
       order1++, order2++) {
    // /
    if (*order1 && *order2) {
      accumulator += *values1 * *values2;
    }

    if (*order1) {
      ++values1;
    }

    if (*order2) {
      ++values2;
    }
  }

  return accumulator;
}

void SpareVector::push(int64_t val) {
  if (val == 0) {
    order.push_back(false);
  } else {
    order.push_back(true);
    values.push_back(val);
  }
}
}  // namespace vector