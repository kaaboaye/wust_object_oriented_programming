#ifndef CLI_AGR_VEHICLE_OR_ACTION_H
#define CLI_AGR_VEHICLE_OR_ACTION_H

#include <string>

namespace cli {
namespace agr {

enum VehicleOrAction {
  VehicleOrAction_bus,
  VehicleOrAction_car,
  VehicleOrAction_exit,
  VehicleOrAction_help,
  VehicleOrAction_undefined,
};

VehicleOrAction cast_vehicle_or_action(const std::string &str);

}  // namespace agr
}  // namespace cli

#endif
