#include <stdlib.h>

#include "car_agr.h"

CarAgr::CarAgr(double weight, double speed, double milage, double burning)
{
  vehicle = new Vehicle(weight, speed, milage, burning);
}

const char *CarAgr::does()
{
  return "beep beep";
}

CarAgr::~CarAgr()
{
  free(vehicle);
}
