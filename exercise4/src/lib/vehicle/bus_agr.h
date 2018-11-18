#ifndef BUS_INH_H
#define BUS_INH_H

#include "vehicle.h"

class BusAgr {
 public:
  Vehicle *vehicle;
  ~BusAgr();

  BusAgr(double weight, double speed, double milage, double burning);

  const char *does();
};

#endif
