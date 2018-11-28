#include <complex>
#include <iostream>

#include "stack.hh"

void int_stack_test() {
  std::cout << "testing int stack" << std::endl;

  Stack<int> int_s;

  int_s.push(2);
  int_s.push(3);
  int_s.push(4);

  for (int i = 0; i < 4; ++i) {
    auto [is_exists, val] = int_s.pop();
    if (is_exists) {
      std::cout << val << std::endl;
    } else {
      std::cout << "stack is empty" << std::endl;
    }
  }
}

void complex_stack_test() {
  std::cout << "testing complex stack" << std::endl;

  using namespace std::complex_literals;

  Stack<std::complex<double>> s;

  s.push(1.0 + 1i);
  s.push(2.0 + 2i);
  s.push(3.0 + 3i);

  for (int i = 0; i < 4; ++i) {
    auto [is_exists, val] = s.pop();
    if (is_exists) {
      std::cout << val << std::endl;
    } else {
      std::cout << "stack is empty" << std::endl;
    }
  }
}

int main() {
  int_stack_test();
  complex_stack_test();

  return 0;
}