#include <stdio.h>

#include "cli.h"
#include "prime.h"

void print_numbers(Number *numbers)
{
  for (Number *number = numbers; number; number = number->next)
  {
    printf("%llu ", number->num);
  }
  printf("\n");
}

void print_slice(Slice slice)
{
  for (
      Number *number = slice.beg;
      number && number->num < slice.end->num;
      number = number->next)
  {
    printf("%llu ", number->num);
  }
  printf("\n");
}