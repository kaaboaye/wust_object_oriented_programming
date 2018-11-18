#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle {
  double _weight;
  double _speed;
  double _milage;
  double _burning;

 public:
  Vehicle(double weight, double speed, double milage, double burning);

  double weight();

  void speed(double speed);
  double speed();

  void milage(double milage);
  double milage();

  double burning();

  virtual const char *does();
};

#endif
