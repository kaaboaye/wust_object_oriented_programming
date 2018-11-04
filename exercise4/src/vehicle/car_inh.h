#ifndef CAR_INH_H
#define CAR_INH_H

#include "vehicle.h"

class CarInh : public Vehicle
{
public:
  CarInh(double weight, double speed, double milage, double burning);

  const char *does();
};

#endif