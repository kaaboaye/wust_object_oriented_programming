#ifndef CLI_INH_ACTION_H
#define CLI_INH_ACTION_H

#include <string>

namespace cli {
namespace inh {
enum Action {
  Action_create_car,
  Action_create_bus,
  Action_get_weight,
  Action_set_speed,
  Action_get_speed,
  Action_set_milage,
  Action_get_milage,
  Action_get_burning,
  Action_does,
  Action_exit,
  Action_help,
  Action_undefined,
};

Action cast_action(const std::string &str);
bool action_depend_on_vehicle(Action action);
}  // namespace inh
}  // namespace cli

#endif
