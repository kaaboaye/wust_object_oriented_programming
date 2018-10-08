#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "cli.h"
#include "prime.h"

static void error(const char *message)
{
  fprintf(stderr, "%s\n", message);
  exit(1);
}

uint64_t *read_range()
{
  uint64_t *range = malloc(sizeof(uint64_t));

  printf("Start: ");
  if (scanf("%llu", range) == EOF)
  {
    error("Field to read begin");
  }

  printf("End: ");
  if (scanf("%llu", range + 1) == EOF)
  {
    error("Field to read end");
  }

  return range;
}

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
      number != slice.end;
      number = number->next)
  {
    printf("%llu ", number->num);
  }
  printf("\n");
}