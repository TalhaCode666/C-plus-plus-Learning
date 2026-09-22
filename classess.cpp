#include <iostream>

/*
https://www.youtube.com/watch?v=8jLOx1hD3_o&t=665s
timestamp: 20:53:36

*/

class Cylinder
{
private:
  // properties
  const double PI{3.14};
  double base_radius{};
  double height{};

public:
  // constructor initilizer
  // Cylinder() : base_radius(0.0), height(0.0) {}
  Cylinder() = default;

  // constructor function with paramerters. (but either way, it can't have return type)
  Cylinder(double base_radius_param, double height_param)
  {
    base_radius = base_radius_param;
    height = height_param;
  }

/*
this->base_radius -- it is representing the class property.. while base_radius is the parameter being passed into the functions.

this is done to not confuse the compiler and dev who without it has to think of variable names; which is awefully harder than ppl assume.
*/

  // setter functions/methods
  void set_base_radius(double base_radius)
  {
    this->base_radius = base_radius;
  }

  void set_height(double height)
  {
    this->height = height;
  }

  // getter functions/methods
  double get_base_radius()
  {
    return base_radius;
  }

  double get_height()
  {
    return height;
  }

  double volume()
  {
    return PI * base_radius * height;
  }
};

int main()
{
  // using constructor
  Cylinder p1(13.9,2.9);

  std::cout << "Base radius: " << p1.get_base_radius() << std::endl;
  std::cout << "Height: " << p1.get_height() << std::endl;
  std::cout << "Result: " << p1.volume() << std::endl;
  
  std::cout << "================================" << std::endl;
  // using manually created methods to inject values
  p1.set_base_radius(9.5);
  p1.set_height(3.5);

  std::cout << "Base radius: " << p1.get_base_radius() << std::endl;
  std::cout << "Height: " << p1.get_height() << std::endl;
  std::cout << "Result: " << p1.volume() << std::endl;

  std::cout << "================================" << std::endl;
  std::cout << "Program worked successfully!" << std::endl;
  return 0;
}