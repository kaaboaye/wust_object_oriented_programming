#include <stdio.h>

#include "bike/bike.h"
#include "vector/cli.h"
#include "vehicle/amphibian.h"

int main() {
  puts("\namphibian");
  {
    vehicle::Amphibian a;
    printf("driving_sound: %s\n", a.driving_sound());
    printf("floating_sound: %s\n", a.floating_sound());
  }

  puts("\nbike");

  {
    bike::Bike b;
    printf("is bike functional? %s\n", b.functional() ? "T" : "N");
  }

  puts("\nSpare vector");
  vector::main();

  return 0;
}
