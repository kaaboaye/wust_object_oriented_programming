/*
  Author: Mieszko Wawrzyniak

  Task: Write a program that finds prime numbers from the defined scope.
*/

#include <stdlib.h>

#include "prime.h"
#include "cli.h"

int main(int argc, char const *argv[])
{
  Number *prime_numbers = malloc(sizeof(Number));
  prime_numbers->num = 2;
  prime_numbers->next = 0;

  Slice result = primes_in_range(prime_numbers, 100000, 100100);
  // print_numbers(prime_numbers);
  print_slice(result);
  return 0;
}
