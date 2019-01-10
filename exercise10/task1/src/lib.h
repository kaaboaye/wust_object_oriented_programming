#ifndef LIB_H
#define LIB_H

#include <deque>
#include <string>
#include <tuple>

namespace symbol {
enum t { __null__, ok, error, empty, not_found, brackets_error };
}  // namespace symbol

namespace lib {

class AssertNeverException {
 public:
  const std::string message;

  AssertNeverException(const std::string& message);
};
void assert_never(std::string message);

template <typename Collection, typename Action>
void each(const Collection& in, const Action&& action) {
  for (const auto& elem : in) {
    action(elem);
  }
}

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