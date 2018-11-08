#include <stdlib.h>

#include "bus_agr.h"

BusAgr::BusAgr(double weight, double speed, double milage, double burning)
{
  vehicle = new Vehicle(weight, speed, milage, burning);
}

const char *BusAgr::does()
{
  return "booo booo";
}

BusAgr::~BusAgr()
{
  free(vehicle);
}