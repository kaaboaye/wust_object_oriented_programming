#include <string>
#include <unordered_map>

#include "vehicle_action.h"

namespace cli
{
namespace agr
{

static std::unordered_map<std::string, VehicleAction> __vehicle_action_strings__ = {
    {"create", VehicleAction_create},
    {"get_weight", VehicleAction_get_weight},
    {"set_speed", VehicleAction_set_speed},
    {"get_speed", VehicleAction_get_speed},
    {"set_milage", VehicleAction_set_milage},
    {"get_milage", VehicleAction_get_milage},
    {"get_burning", VehicleAction_get_burning},
    {"does", VehicleAction_does},
};

VehicleAction cast_vehicle_action(const std::string &str)
{
  auto va_iter = __vehicle_action_strings__.find(str);
  return va_iter != __vehicle_action_strings__.end() ? va_iter->second : VehicleAction_undefined;
}

} // namespace agr
} // namespace cli
