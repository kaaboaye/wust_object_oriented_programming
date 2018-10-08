#include <stdlib.h>
#include <stdbool.h>

#include "prime.h"

Number *prime_next(Number *prime_numbers, Number *number)
{
  if (number->next)
  {
    return number->next;
  }

  Number *next = malloc(sizeof(Number));
  next->num = number->num + 1;
  next->next = 0;

  while (!is_prime(prime_numbers, next->num))
  {
    ++next->num;
  }

  number->next = next;
  return next;
}

bool is_prime(Number *prime_numbers, uint64_t num)
{
  for (Number *prime = prime_numbers; prime; prime = prime->next)
  {
    if (num % prime->num == 0)
    {
      return false;
    }
  }

  return true;
}

Slice primes_in_range(Number *prime_numbers, uint64_t *range)
{
  Number *result;
  for (
      result = prime_numbers;
      result->num < range[0];
      result = prime_next(prime_numbers, result))
    ;

  if (result->num == range[1])
  {
    Slice s = {result, result};
    return s;
  }

  if (result->num > range[1])
  {
    Slice s = {0, 0};
    return s;
  }

  Number *tail = result;

  while (tail->num < range[1])
  {
    Number *next_number = prime_next(prime_numbers, tail);

    if (next_number->num > range[1])
    {
      Slice s = {result, tail->next};
      return s;
    }

    tail->next = next_number;
    tail = next_number;
  }

  Slice s = {result, tail->next};
  return s;
}