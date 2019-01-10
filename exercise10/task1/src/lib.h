#ifndef LIB_H
#define LIB_H

#include <deque>
#include <tuple>

namespace symbol {
enum t { ok, error, empty, not_found, brackets_error };
}  // namespace symbol

namespace lib {
class AssertNeverException {};
void assert_never();

template <typename CollectionIn, typename CollectionOut,
          typename Transformation>
CollectionOut map(const CollectionIn& in, const Transformation&& transform) {
  CollectionOut out;
  for (const auto& elem : in) {
    out.push_back(transform(elem));
  }

  return out;
}

template <typename Collection, typename Check>
Collection filter(const Collection& in, const Check&& check) {
  Collection out;
  for (const auto& elem : in) {
    if (check(elem)) {
      out.push_back(elem);
    }
  }

  return out;
}

}  // namespace lib

#endif