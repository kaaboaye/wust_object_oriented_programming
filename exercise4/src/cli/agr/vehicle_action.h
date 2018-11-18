#ifndef CLI_AGR_VEHICLE_ACTION_H
#define CLI_AGR_VEHICLE_ACTION_H

#include <string>

namespace cli {
namespace agr {
enum VehicleAction {
  VehicleAction_create,
  VehicleAction_get_weight,
  VehicleAction_set_speed,
  VehicleAction_get_speed,
  VehicleAction_set_milage,
  VehicleAction_get_milage,
  VehicleAction_get_burning,
  VehicleAction_does,
  VehicleAction_undefined,
};

VehicleAction cast_vehicle_action(const std::string &str);
}  // namespace agr
}  // namespace cli

#endif
