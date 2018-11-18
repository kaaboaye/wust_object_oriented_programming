#include <string>
#include <unordered_map>

#include "vehicle_or_action.h"

namespace cli {
namespace agr {

static std::unordered_map<std::string, VehicleOrAction>
    __vehicle_or_action_strings__ = {
        {"bus", VehicleOrAction_bus},
        {"car", VehicleOrAction_car},
        {"exit", VehicleOrAction_exit},
        {"help", VehicleOrAction_help},
};

VehicleOrAction cast_vehicle_or_action(const std::string &str) {
  auto voa_iter = __vehicle_or_action_strings__.find(str);
  return voa_iter != __vehicle_or_action_strings__.end()
             ? voa_iter->second
             : VehicleOrAction_undefined;
}
}  // namespace agr
}  // namespace cli
