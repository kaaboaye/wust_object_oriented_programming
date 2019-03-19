#include <stdint.h>
#include <cstdio>
#include <ctime>
#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <thread>
#include <vector>

template <typename elem_t>
class not_a_forward_list : public std::forward_list<elem_t> {
 public:
  inline void push_back(const elem_t& elem) {
    this->std::forward_list<elem_t>::push_front(elem);
  }
  inline void push_back(elem_t& elem) {
    this->std::forward_list<elem_t>::push_front(elem);
  }
};

typedef uint64_t num_t;
#define TRIES 10
#define NUMBERS 1000000

template <typename container_t>
bool is_prime(const container_t& primes, const num_t num) {
  for (const num_t prime : primes) {
    if (num % prime == 0) {
      return false;
    }
  }
  return true;
}

template <typename container_t>
void find_primes() {
  container_t primes;
  for (num_t num = 2; num < NUMBERS; ++num) {
    if (is_prime(primes, num)) {
      primes.push_back(num);
    }
  }
}

template <typename container_t>
void find_n_times() {
  clock_t start = std::clock();
  for (num_t i = 0; i < TRIES; ++i) {
    find_primes<container_t>();
  }

  double time = (std::clock() - start) / (double)CLOCKS_PER_SEC;
  std::cout << "time: " << time << std::endl;
}

int main(int argc, char const* argv[]) {
  std::thread vec(find_n_times<std::vector<num_t>>);
  std::thread deq(find_n_times<std::deque<num_t>>);
  std::thread lis(find_n_times<std::list<num_t>>);

  // std::cout << "std::vector ";
  // find_n_times<std::vector<num_t>>(tries, numbers);

  // std::cout << "std::deque ";
  // find_n_times<std::deque<num_t>>(tries, numbers);

  // std::cout << "std::list ";
  // find_n_times<std::list<num_t>>(tries, numbers);

  // std::cout << "std::forward_list ";
  // find_n_times<not_a_forward_list<num_t>>(tries, numbers);

  return 0;
}
