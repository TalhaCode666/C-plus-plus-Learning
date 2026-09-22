#include <iostream>
#include "Cylinder.h" // class declarations
#include "constants.h" // constants
#include "cylinder.cpp" // class definations

/*
https://www.youtube.com/watch?v=8jLOx1hD3_o&t=665s
timestamp: 21:30:53

*/

int main()
{
  // using constructor
  Cylinder test1(13.9,2.9);

  std::cout << "Base radius: " << test1.get_base_radius() << std::endl;
  std::cout << "Height: " << test1.get_height() << std::endl;
  std::cout << "Result: " << test1.volume() << std::endl;
  
  std::cout << "================================" << std::endl;
  // using manually created methods to inject values
  Cylinder test2;
  test2.set_base_radius(2.5);
  test2.set_height(3.5);

  std::cout << "Base radius: " << test2.get_base_radius() << std::endl;
  std::cout << "Height: " << test2.get_height() << std::endl;
  std::cout << "Result: " << test2.volume() << std::endl;

  std::cout << "================================" << std::endl;
  std::cout << "Program worked successfully!" << std::endl;
  return 0;
}