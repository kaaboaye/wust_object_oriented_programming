#include <string>
#include <unordered_map>
#include <unordered_set>

#include "action.h"

namespace cli
{
namespace inh
{

static std::unordered_map<std::string, Action> __action_strings__ = {
    {"create_car", Action_create_car},
    {"create_bus", Action_create_bus},
    {"get_weight", Action_get_weight},
    {"set_speed", Action_set_speed},
    {"get_speed", Action_get_speed},
    {"set_milage", Action_set_milage},
    {"get_milage", Action_get_milage},
    {"get_burning", Action_get_burning},
    {"does", Action_does},
    {"exit", Action_exit},
    {"help", Action_help},
};

static std::unordered_set<Action> __actions_depend_vehicle__ = {
    Action_get_weight,
    Action_set_speed,
    Action_get_speed,
    Action_set_milage,
    Action_get_milage,
    Action_get_burning,
    Action_does,
};

Action cast_action(const std::string &str)
{
  auto a_iter = __action_strings__.find(str);
  return a_iter != __action_strings__.end() ? a_iter->second : Action_undefined;
}

bool action_depend_on_vehicle(Action action)
{
  return __actions_depend_vehicle__.find(action) != __actions_depend_vehicle__.end();
}

} // namespace inh
} // namespace cli