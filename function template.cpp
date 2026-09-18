#include <iostream>
#include <cmath>
#include <typeinfo> // type checker

/*
https://www.youtube.com/watch?v=8jLOx1hD3_o&t=665s
timestamp: 18:48:58

*/

/*
a template is blueprint to avoid repitition.. argument type is used.. can't work with pointers, and
multiple types properly.. template can get confused when passed  multi type, string to digits, pass by refrence or the value. below example is by refrence, by value, just don't add '&' to things
*/

// Base Template
template <typename T>
const T &maximum(const T &a, const T &b) // taking refrences of arguments
{
  return (a > b) ? a : b;
}

// Specialization (Now it matches perfectly!)
template <>
const std::string &maximum<std::string>(const std::string &a, const std::string &b)
{
  return (a.length() > b.length()) ? a : b;
}

int main()
{
  int a{10};
  int b{53};

  double c{12.4};
  double d{31.4};

  std::string e{"Hello"};
  std::string f{"World!!!!"};

  std::cout << "max(int): " << maximum(a, b) << std::endl;
  std::cout << "max(double): " << maximum(c, d) << std::endl;
  std::cout << "max(explicit type): " << maximum<int>(d, a) << std::endl;
  std::cout << "max(str): " << maximum(e, f) << std::endl;

  std::cout << "================================" << std::endl;
  std::cout << "Program worked successfully!" << std::endl;
  return 0;
}