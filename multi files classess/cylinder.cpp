#include "Cylinder.h"
#include "constants.h"

Cylinder::Cylinder(double base_radius, double height)
{
  this->base_radius = base_radius;
  this->height = height;
}

double Cylinder::volume()
{
  return PI * base_radius * base_radius * height;
}

/*
this->base_radius -- it is representing the class property.. while base_radius is the parameter being passed into the functions.

this is done to not confuse the compiler and dev who without it has to think of variable names; which is awefully harder than ppl assume.
*/

// setter functions/methods
void Cylinder::set_base_radius(double base_radius)
{
  this->base_radius = base_radius;
}

void Cylinder::set_height(double height)
{
  this->height = height;
}

// getter functions/methods
double Cylinder::get_base_radius()
{
  return base_radius;
}

double Cylinder::get_height()
{
  return height;
}