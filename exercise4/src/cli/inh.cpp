#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include "inh.h"
#include "../vehicle/vehicle.h"
#include "../vehicle/car_inh.h"
#include "../vehicle/bus_inh.h"

enum __action__
{
  __create_car__,
  __create_bus__,
  __get_weight__,
  __set_speed__,
  __get_speed__,
  __set_milage__,
  __get_milage__,
  __get_burning__,
  __does__,
  __exit__,
  __help__,
  __undefined__
};

static std::unordered_map<std::string, __action__> __action_strings__ = {
    {"create_car", __create_car__},
    {"create_bus", __create_bus__},
    {"get_weight", __get_weight__},
    {"set_speed", __set_speed__},
    {"get_speed", __get_speed__},
    {"set_milage", __set_milage__},
    {"get_milage", __get_milage__},
    {"get_burning", __get_burning__},
    {"does", __does__},
    {"exit", __exit__},
    {"help", __help__},
};

static std::unordered_set<__action__> __actions_depend_vehicle__ = {
    __get_weight__,
    __set_speed__,
    __get_speed__,
    __set_milage__,
    __get_milage__,
    __get_burning__,
    __does__,
};

static __action__ cast_action(std::string str)
{
  auto action = __action_strings__.find(str);
  return action != __action_strings__.end() ? action->second : __undefined__;
}

struct __vehicle_options__
{
  double weight;
  double speed;
  double milage;
  double burning;
};

static __vehicle_options__ read_vehicle_options()
{
  double weight;
  double speed;
  double milage;
  double burning;

  std::cout << "Provide vehicle weight: ";
  std::cin >> weight;

  std::cout << "Provide vehicle speed: ";
  std::cin >> speed;

  std::cout << "Provide vehicle milage: ";
  std::cin >> milage;

  std::cout << "Provide vehicle burning: ";
  std::cin >> burning;

  return __vehicle_options__{
      weight,
      speed,
      milage,
      burning,
  };
}

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

void cli_inh()
{
  Vehicle *vehicle = nullptr;

  usage();

  for (;;)
  {
    std::cout << "> ";

    std::string str_action;
    std::cin >> str_action;
    __action__ action = cast_action(str_action);

    if (!vehicle && __actions_depend_vehicle__.find(action) != __actions_depend_vehicle__.end())
    {
      std::cout << "In order to use this command you need to create a vehicle ~grrr~" << std::endl;
      continue;
    }

    switch (action)
    {
    case __create_car__:
    {
      std::cout << "Creating car…" << std::endl;
      __vehicle_options__ opts = read_vehicle_options();

      if (vehicle)
      {
        free(vehicle);
      }
      vehicle = new CarInh(opts.weight, opts.speed, opts.milage, opts.burning);
      break;
    }

    case __create_bus__:
    {
      std::cout << "Creating bus…" << std::endl;
      __vehicle_options__ opts = read_vehicle_options();

      if (vehicle)
      {
        free(vehicle);
      }
      vehicle = new BusInh(opts.weight, opts.speed, opts.milage, opts.burning);
      break;
    }

    case __get_weight__:
      std::cout << "Vehicle weight: " << vehicle->weight() << std::endl;
      break;

    case __set_speed__:
    {
      double speed;

      std::cout << "Provide speed: ";
      std::cin >> speed;

      vehicle->speed(speed);
      break;
    }

    case __get_speed__:
      std::cout << "Vehicle speed: " << vehicle->speed() << std::endl;
      break;

    case __set_milage__:
    {
      double milage;

      std::cout << "Provide milage: ";
      std::cin >> milage;

      vehicle->milage(milage);
      break;
    }

    case __get_milage__:
      std::cout << "Vehicle milage: " << vehicle->milage() << std::endl;
      break;

    case __get_burning__:
      std::cout << "Vehicle burning:" << vehicle->burning() << std::endl;
      break;

    case __does__:
      std::cout << "This vehicle does: " << vehicle->does() << std::endl;
      break;

    case __exit__:
      std::cout << std::endl;

      if (vehicle)
      {
        free(vehicle);
      }

      return;

    case __help__:
      usage();
      break;

    case __undefined__:
      std::cout << "Unknown action :(" << std::endl;
      break;
    }
  }
}