#include <iostream>

#include "vehicle_options.h"

namespace cli
{

VehicleOptions read_vehicle_options()
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

  return VehicleOptions{
      weight,
      speed,
      milage,
      burning,
  };
}
} // namespace cli
