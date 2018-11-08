#include "vehicle.h"
#include "car_inh.h"

CarInh::CarInh(double weight, double speed, double milage, double burning)
    : Vehicle(weight, speed, milage, burning) {}

const char *CarInh::does()
{
  return "beep beep";
}