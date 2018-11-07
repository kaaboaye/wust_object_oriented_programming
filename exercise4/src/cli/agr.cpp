#include <iostream>
#include <string>
#include <unordered_map>

#include "agr.h"
#include "../vehicle/car_agr.h"
#include "../vehicle/bus_agr.h"

enum __vehicle_or_action__
{
  __bus__,
  __car__,
  __exit__,
  __help__,
  __undefined_vehicle_or_action__,
};

static std::unordered_map<std::string, __vehicle_or_action__> __vehicle_or_action_strings__ = {
    {"bus", __bus__},
    {"car", __car__},
    {"exit", __exit__},
    {"help", __help__},
};

static __vehicle_or_action__ cast_vehicle_or_action(std::string str)
{
  auto voa = __vehicle_or_action_strings__.find(str);
  return voa != __vehicle_or_action_strings__.end() ? voa->second : __undefined_vehicle_or_action__;
}

enum __vehicle_action__
{
  __create__,
  __get_weight__,
  __set_speed__,
  __get_speed__,
  __set_milage__,
  __get_milage__,
  __get_burning__,
  __does__,
  __undefined_vehicle_action__,
};

static std::unordered_map<std::string, __vehicle_action__> __vehicle_action_strings__ = {
    {"create", __create__},
    {"get_weight", __get_weight__},
    {"set_speed", __set_speed__},
    {"get_speed", __get_speed__},
    {"set_milage", __set_milage__},
    {"get_milage", __get_milage__},
    {"get_burning", __get_burning__},
    {"does", __does__},
};

static __vehicle_action__ cast_vehicle_action(std::string str)
{
  auto va = __vehicle_action_strings__.find(str);
  return va != __vehicle_action_strings__.end() ? va->second : __undefined_vehicle_action__;
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
  std::cout << "Welcome in aggregation mode :/" << std::endl
            << "Command schema:" << std::endl
            << "\tvehicle_or_action [vehicle_action]" << std::endl
            << std::endl
            << "vehicle_or_action options:" << std::endl
            << "\tbus" << std::endl
            << "\tcar" << std::endl
            << "\texit" << std::endl
            << "\thelp" << std::endl
            << std::endl
            << "vehicle_action options:" << std::endl
            << "\tcreate" << std::endl
            << "\tget_weight" << std::endl
            << "\tset_speed" << std::endl
            << "\tget_speed" << std::endl
            << "\tset_milage" << std::endl
            << "\tget_milage" << std::endl
            << "\tget_burning" << std::endl
            << "\tdoes" << std::endl
            << std::endl;
}

void cli_arg()
{
  CarAgr *car = nullptr;
  BusAgr *bus = nullptr;

  usage();

  for (;;)
  {
    std::cout << "aggregate > ";

    std::string str;
    std::cin >> str;
    __vehicle_or_action__ vehicle_or_action = cast_vehicle_or_action(str);

    switch (vehicle_or_action)
    {

    case __car__:
    {
      std::string str;
      std::cin >> str;
      __vehicle_action__ vehicle_action = cast_vehicle_action(str);

      if (!car && vehicle_action != __create__ && vehicle_action != __undefined_vehicle_action__)
      {
        std::cout << "In order to use this command you need to create a car ~grrr~" << std::endl;
        continue;
      }

      switch (vehicle_action)
      {
      case __create__:
      {
        std::cout << "Creating car…" << std::endl;
        __vehicle_options__ opts = read_vehicle_options();

        if (car)
        {
          free(car);
        }
        car = new CarAgr(opts.weight, opts.speed, opts.milage, opts.burning);
        break;
      }

      case __get_weight__:
        std::cout << "Car weight: " << car->vehicle->weight() << std::endl;
        break;

      case __set_speed__:
      {
        double speed;

        std::cout << "Car speed: ";
        std::cin >> speed;

        car->vehicle->speed(speed);
        break;
      }

      case __get_speed__:
        std::cout << "Car speed: " << car->vehicle->speed() << std::endl;
        break;

      case __set_milage__:
      {
        double milage;

        std::cout << "Car milage: ";
        std::cin >> milage;

        car->vehicle->milage(milage);
        break;
      }

      case __get_milage__:
        std::cout << "Car milage: " << car->vehicle->milage() << std::endl;
        break;

      case __get_burning__:
        std::cout << "Car burning: " << car->vehicle->burning() << std::endl;
        break;

      case __does__:
        std::cout << "This car does: " << car->does() << std::endl;
        break;

      case __undefined_vehicle_action__:
        std::cout << "Unknown action :(" << std::endl;
        break;
      }

      break;
    }

    case __bus__:
    {
      std::string str;
      std::cin >> str;
      __vehicle_action__ vehicle_action = cast_vehicle_action(str);

      if (!bus && vehicle_action != __create__ && vehicle_action != __undefined_vehicle_action__)
      {
        std::cout << "In order to use this command you need to create a bus ~grrr~" << std::endl;
        continue;
      }

      switch (vehicle_action)
      {
      case __create__:
      {
        std::cout << "Creating bus…" << std::endl;
        __vehicle_options__ opts = read_vehicle_options();

        if (bus)
        {
          free(bus);
        }
        bus = new BusAgr(opts.weight, opts.speed, opts.milage, opts.burning);
        break;
      }

      case __get_weight__:
        std::cout << "Bus weight: " << bus->vehicle->weight() << std::endl;
        break;

      case __set_speed__:
      {
        double speed;

        std::cout << "Bus speed: ";
        std::cin >> speed;

        bus->vehicle->speed(speed);
        break;
      }

      case __get_speed__:
        std::cout << "Bus speed: " << bus->vehicle->speed() << std::endl;
        break;

      case __set_milage__:
      {
        double milage;

        std::cout << "Bus milage: ";
        std::cin >> milage;

        bus->vehicle->milage(milage);
        break;
      }

      case __get_milage__:
        std::cout << "Bus milage: " << bus->vehicle->milage() << std::endl;
        break;

      case __get_burning__:
        std::cout << "Bus burning: " << bus->vehicle->burning() << std::endl;
        break;

      case __does__:
        std::cout << "This bus does: " << bus->does() << std::endl;
        break;

      case __undefined_vehicle_action__:
        std::cout << "Unknown action :(" << std::endl;
        break;
      }

      break;
    }

    case __exit__:
      std::cout << std::endl;

      if (car)
      {
        free(car);
      }

      if (bus)
      {
        free(bus);
      }

      return;

    case __help__:
      usage();
      break;

    case __undefined_vehicle_or_action__:
      std::cout << "Unknown action :(" << std::endl;
      break;
    }
  }
}