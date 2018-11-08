#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include "inh.h"
#include "action.h"
#include "../vehicle_options.h"
#include "../../lib/vehicle/vehicle.h"
#include "../../lib/vehicle/car_inh.h"
#include "../../lib/vehicle/bus_inh.h"

namespace cli
{
namespace inh
{

static void usage()
{
  std::cout << "Welcome to inheritance mode :D" << std::endl
            << std::endl
            << "Commands:" << std::endl
            << "\tcreate_car" << std::endl
            << "\tcreate_bus" << std::endl
            << "\tget_weight" << std::endl
            << "\tset_speed" << std::endl
            << "\tget_speed" << std::endl
            << "\tset_milage" << std::endl
            << "\tget_milage" << std::endl
            << "\tget_burning" << std::endl
            << "\tdoes" << std::endl
            << "\texit" << std::endl
            << "\thelp" << std::endl
            << std::endl;
}

void main()
{
  Vehicle *vehicle = nullptr;

  usage();

  for (;;)
  {
    std::cout << "inheritance > ";

    std::string str_action;
    std::cin >> str_action;
    Action action = cast_action(str_action);

    if (!vehicle && action_depend_on_vehicle(action))
    {
      std::cout << "In order to use this command you need to create a vehicle ~grrr~" << std::endl;
      continue;
    }

    switch (action)
    {
    case Action_create_car:
    {
      std::cout << "Creating car…" << std::endl;
      VehicleOptions opts = read_vehicle_options();

      if (vehicle)
      {
        free(vehicle);
      }
      vehicle = new CarInh(opts.weight, opts.speed, opts.milage, opts.burning);
      break;
    }

    case Action_create_bus:
    {
      std::cout << "Creating bus…" << std::endl;
      VehicleOptions opts = read_vehicle_options();

      if (vehicle)
      {
        free(vehicle);
      }
      vehicle = new BusInh(opts.weight, opts.speed, opts.milage, opts.burning);
      break;
    }

    case Action_get_weight:
      std::cout << "Vehicle weight: " << vehicle->weight() << std::endl;
      break;

    case Action_set_speed:
    {
      double speed;

      std::cout << "Provide speed: ";
      std::cin >> speed;

      vehicle->speed(speed);
      break;
    }

    case Action_get_speed:
      std::cout << "Vehicle speed: " << vehicle->speed() << std::endl;
      break;

    case Action_set_milage:
    {
      double milage;

      std::cout << "Provide milage: ";
      std::cin >> milage;

      vehicle->milage(milage);
      break;
    }

    case Action_get_milage:
      std::cout << "Vehicle milage: " << vehicle->milage() << std::endl;
      break;

    case Action_get_burning:
      std::cout << "Vehicle burning: " << vehicle->burning() << std::endl;
      break;

    case Action_does:
      std::cout << "This vehicle does: " << vehicle->does() << std::endl;
      break;

    case Action_exit:
      std::cout << std::endl;

      if (vehicle)
      {
        free(vehicle);
      }

      return;

    case Action_help:
      usage();
      break;

    case Action_undefined:
      std::cout << "Unknown action :(" << std::endl;
      break;
    }
  }
}
} // namespace inh
} // namespace cli
