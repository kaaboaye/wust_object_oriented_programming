#ifndef VEHICLE_VEHICLE_H
#define VEHICLE_VEHICLE_H

namespace vehicle {
class Vehicle {
 public:
  virtual const char *sound() = 0;
};
}  // namespace vehicle

#endif
