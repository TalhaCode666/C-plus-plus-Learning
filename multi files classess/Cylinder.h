#ifndef CYLINDER_H
#define CYLINDER_H

#include "constants.h"

class Cylinder
{
private:
  // properties
  double base_radius{};
  double height{};

public:
  // constructor initilizer
  // Cylinder() : base_radius(0.0), height(0.0) {}
  Cylinder() = default;

  // constructor function with paramerters defination (it can't have return type)
  Cylinder(double base_radius_param, double height_param);

  // setter functions/methods
  void set_base_radius(double base_radius);
  void set_height(double height);

  // getter functions/methods
  double get_base_radius();
  double get_height();
  double volume();
};

#endif