#include <iostream>
#include <string>

#include "agr.h"
#include "vehicle_or_action.h"
#include "vehicle_action.h"
#include "../vehicle_options.h"
#include "../../lib/vehicle/car_agr.h"
#include "../../lib/vehicle/bus_agr.h"

namespace cli
{
namespace agr
{

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

void main()
{
  CarAgr *car = nullptr;
  BusAgr *bus = nullptr;

  usage();

  for (;;)
  {
    std::cout << "aggregate > ";

    std::string str;
    std::cin >> str;
    VehicleOrAction vehicle_or_action = cast_vehicle_or_action(str);

    switch (vehicle_or_action)
    {

    case VehicleOrAction_car:
    {
      std::string str;
      std::cin >> str;
      VehicleAction vehicle_action = cast_vehicle_action(str);

      if (!car && vehicle_action != VehicleAction_create && vehicle_action != VehicleAction_undefined)
      {
        std::cout << "In order to use this command you need to create a car ~grrr~" << std::endl;
        continue;
      }

      switch (vehicle_action)
      {
      case VehicleAction_create:
      {
        std::cout << "Creating car…" << std::endl;
        VehicleOptions opts = read_vehicle_options();

        if (car)
        {
          free(car);
        }
        car = new CarAgr(opts.weight, opts.speed, opts.milage, opts.burning);
        break;
      }

      case VehicleAction_get_weight:
        std::cout << "Car weight: " << car->vehicle->weight() << std::endl;
        break;

      case VehicleAction_set_speed:
      {
        double speed;

        std::cout << "Car speed: ";
        std::cin >> speed;

        car->vehicle->speed(speed);
        break;
      }

      case VehicleAction_get_speed:
        std::cout << "Car speed: " << car->vehicle->speed() << std::endl;
        break;

      case VehicleAction_set_milage:
      {
        double milage;

        std::cout << "Car milage: ";
        std::cin >> milage;

        car->vehicle->milage(milage);
        break;
      }

      case VehicleAction_get_milage:
        std::cout << "Car milage: " << car->vehicle->milage() << std::endl;
        break;

      case VehicleAction_get_burning:
        std::cout << "Car burning: " << car->vehicle->burning() << std::endl;
        break;

      case VehicleAction_does:
        std::cout << "This car does: " << car->does() << std::endl;
        break;

      case VehicleAction_undefined:
        std::cout << "Unknown action :(" << std::endl;
        break;
      }

      break;
    }

    case VehicleOrAction_bus:
    {
      std::string str;
      std::cin >> str;
      VehicleAction vehicle_action = cast_vehicle_action(str);

      if (!bus && vehicle_action != VehicleAction_create && vehicle_action != VehicleAction_undefined)
      {
        std::cout << "In order to use this command you need to create a bus ~grrr~" << std::endl;
        continue;
      }

      switch (vehicle_action)
      {
      case VehicleAction_create:
      {
        std::cout << "Creating bus…" << std::endl;
        VehicleOptions opts = read_vehicle_options();

        if (bus)
        {
          free(bus);
        }
        bus = new BusAgr(opts.weight, opts.speed, opts.milage, opts.burning);
        break;
      }

      case VehicleAction_get_weight:
        std::cout << "Bus weight: " << bus->vehicle->weight() << std::endl;
        break;

      case VehicleAction_set_speed:
      {
        double speed;

        std::cout << "Bus speed: ";
        std::cin >> speed;

        bus->vehicle->speed(speed);
        break;
      }

      case VehicleAction_get_speed:
        std::cout << "Bus speed: " << bus->vehicle->speed() << std::endl;
        break;

      case VehicleAction_set_milage:
      {
        double milage;

        std::cout << "Bus milage: ";
        std::cin >> milage;

        bus->vehicle->milage(milage);
        break;
      }

      case VehicleAction_get_milage:
        std::cout << "Bus milage: " << bus->vehicle->milage() << std::endl;
        break;

      case VehicleAction_get_burning:
        std::cout << "Bus burning: " << bus->vehicle->burning() << std::endl;
        break;

      case VehicleAction_does:
        std::cout << "This bus does: " << bus->does() << std::endl;
        break;

      case VehicleAction_undefined:
        std::cout << "Unknown action :(" << std::endl;
        break;
      }

      break;
    }

    case VehicleOrAction_exit:
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

    case VehicleOrAction_help:
      usage();
      break;

    case VehicleOrAction_undefined:
      std::cout << "Unknown action :(" << std::endl;
      break;
    }
  }
}
} // namespace agr
} // namespace cli
