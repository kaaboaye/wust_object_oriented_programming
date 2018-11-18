/*
  Author: Mieszko Wawrzyniak

  Task: Write a program that finds prime numbers from the defined scope.
*/

#include <stdint.h>
#include <stdlib.h>

#include "cli.h"
#include "prime.h"

int main(int argc, char const *argv[]) {
  Number *prime_numbers = malloc(sizeof(Number));
  prime_numbers->num = 2;
  prime_numbers->next = 0;

  while (true) {
    uint64_t *range = read_range();
    Slice result = primes_in_range(prime_numbers, range);
    print_slice(result);
  }

  return 0;
}
