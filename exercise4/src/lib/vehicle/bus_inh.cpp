#include "bus_inh.h"

BusInh::BusInh(double weight, double speed, double milage, double burning)
    : Vehicle(weight, speed, milage, burning) {}

const char *BusInh::does() { return "buuuu buuuu"; }
