#ifndef BUS_INH_H
#define BUS_INH_H

#include "vehicle.h"

class BusInh : public Vehicle {
 public:
  BusInh(double weight, double speed, double milage, double burning);

  const char *does();
};

#endif
