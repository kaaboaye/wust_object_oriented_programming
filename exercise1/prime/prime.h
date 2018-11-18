#ifndef PRIME_H
#define PRIME_H

#include <stdbool.h>
#include <stdint.h>

typedef struct _number_elem {
  uint64_t num;
  struct _number_elem *next;
} Number;

typedef struct {
  Number *beg;
  Number *end;
} Slice;

Number *prime_next(Number *prime_numbers, Number *number);
bool is_prime(Number *prime_numbers, uint64_t num);
Slice primes_in_range(Number *prime_numbers, uint64_t *range);

#endif
