#ifndef CAR_AGR_H
#define CAR_AGR_H

#include "vehicle.h"

class CarAgr
{
public:
  Vehicle *vehicle;

  CarAgr(double weight, double speed, double milage, double burning);

  const char *does();
};

#endif