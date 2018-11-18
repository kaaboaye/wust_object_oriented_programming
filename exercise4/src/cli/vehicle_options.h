#ifndef CLI_VEHICLE_OPTIONS_H
#define CLI_VEHICLE_OPTIONS_H

#include <iostream>

namespace cli {

struct VehicleOptions {
  double weight;
  double speed;
  double milage;
  double burning;
};

VehicleOptions read_vehicle_options();
}  // namespace cli

#endif
