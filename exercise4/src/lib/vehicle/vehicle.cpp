#include "vehicle.h"

Vehicle::Vehicle(double weight, double speed, double milage, double burning) {
  _weight = weight > 0 ? weight : 0;
  _speed = speed;
  _milage = milage > 0 ? milage : 0;
  _burning = burning > 0 ? burning : 0;
}

double Vehicle::weight() { return _weight; }

void Vehicle::speed(double speed) { _speed = speed; }

double Vehicle::speed() { return _speed; }

void Vehicle::milage(double milage) { _milage = milage > 0 ? milage : 0; }

double Vehicle::milage() { return _milage; }

double Vehicle::burning() { return _burning; }

const char *Vehicle::does() { return "beep beep"; }
