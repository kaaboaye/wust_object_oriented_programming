#include <stdio.h>

#include "vehicle/amphibian.h"

#include "vector/cli.h"

int main() {
  vehicle::Amphibian a;

  puts("First part");
  printf("driving_sound: %s\n", a.driving_sound());
  printf("floating_sound: %s\n", a.floating_sound());

  puts("\nSpare vector");
  vector::main();

  return 0;
}
