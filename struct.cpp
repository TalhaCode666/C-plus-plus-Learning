#include <iostream>
#include <string>
#include <string_view> // helps us avoid string copies..

/*
https://www.youtube.com/watch?v=8jLOx1hD3_o&t=665s
timestamp: 22:52:48

*/

struct Values
{
  // by default, struct members are public. classess are private by default.
  double x{};
  double y{};
};

/*
const Values &points -- this takes created object by refrence to avoid copies, and makes it const so, we don't change things on the go, specially for printing stuff..

another major thing is that the size of struct/classess are depended on its members not including functions. so, in our case, it would 16, why? because double is 8 bytes, and we have 2.. so 8x2..
*/

void print_info(const Values &points)
{
  std::cout << "Point [x: " << points.x << " , y: " << points.y << "]" << std::endl;
  std::cout << "sizeof(&points): " << sizeof(points) << " bytes" << std::endl; // size of struct
}

int main()
{
  Values p1;
  p1.x = 32.5;
  p1.y = 12.5;
  print_info(p1);

  std::cout << "================================" << std::endl;
  std::cout << "Program worked successfully!" << std::endl;
  return 0;
}