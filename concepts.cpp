#include <iostream>
#include <string>
#include <cstring>
#include <concepts>

/*
https://www.youtube.com/watch?v=8jLOx1hD3_o&t=665s
timestamp: 19:25:34

*/

/*
In C++, a concept is a named set of requirements and compile-time constraints placed on template arguments. meaning it would work with certain values or certain validations.

template <std::integral T> // one other way to force it..
const T &maximum(const T &a, const T &b) requires std::integral<T> // onother way to force it..
{...}

*/

// Base Template
template <typename T>
  requires std::integral<T>
const T &maximum(const T &a, const T &b) // taking refrences of arguments
{
  return (a > b) ? a : b;
}

// specifically takes both parameters as floats, otherwise ERROR!
auto add(std::floating_point auto const &a, std::floating_point auto const &b)
{
  return a + b;
}

int main()
{
  int a{10};
  int b{53};

  double c{12.4};
  double d{31.4};

  std::cout << "max(must be int): " << maximum(a, b) << std::endl;
  std::cout << "add(must be float): " << add(c, d) << std::endl;

  std::cout << "================================" << std::endl;
  std::cout << "Program worked successfully!" << std::endl;
  return 0;
}