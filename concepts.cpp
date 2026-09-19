#include <iostream>
#include <string>
#include <cstring>
#include <concepts>

/*
https://www.youtube.com/watch?v=8jLOx1hD3_o&t=665s
timestamp: 19:42:48

*/

/*
In C++, a concept is a named set of requirements and compile-time constraints placed on template arguments. meaning it would work with certain values or certain validations.

template <std::integral T> // one other way to force it..
const T &maximum(const T &a, const T &b) requires std::integral<T> // onother way to force it..
{...}

*/

// Base Template
template <typename T>
  requires std::is_integral_v<T>         // built-in concept
const T &maximum(const T &a, const T &b) // taking refrences of arguments
{
  return (a > b) ? a : b;
}

// specifically takes both parameters as floats, otherwise ERROR!
auto add(std::floating_point auto const &a, std::floating_point auto const &b)
{
  return a + b;
}

// custom concept
template <typename T> // this only allows ints
concept MyIntegral = std::is_integral_v<T>;

template <typename T> // this only allows floats
concept MyIntegral2 = std::is_floating_point_v<T>;

template <typename T> // this only allows conditional
concept MyMultiplyable = requires(T const &a, T const &b) {
  a * b; // if this check passess (can be multiplied), it is valid.. works for both int & double
};

template <typename T> // this only allows multi conditional..
concept MyIncrementals = requires(T a, T b) {
  a += 1;
  ++a;
  a++;
};

// implementation of custom concept
template <typename T>
  requires MyIntegral<T>
T multiply(T const &a, T const &b)
{
  return a * b;
}

template <typename T>
  requires MyMultiplyable<T>
T CustomAdd(T const &a, T const &b)
{
  return a + b;
}

template <typename T>
  requires MyIncrementals<T>
T CustomMultiIncr(T a, T b)
{
  return a * a;
}

int main()
{
  int a{10};
  int b{53};

  double c{12.4};
  double d{31.4};

  std::cout << "max(must be int): " << maximum(a, b) << std::endl;
  std::cout << "add(must be float): " << add(c, d) << std::endl;
  std::cout << "multiply(must be integer): " << multiply(a, b) << std::endl;
  std::cout << "CustomAdd(must fullfill condition): " << CustomAdd(a, b) << std::endl;
  std::cout << "CustomMultiIncr(must fullfill multi condition): " << CustomMultiIncr(a, b) << std::endl;

  std::cout << "================================" << std::endl;
  std::cout << "Program worked successfully!" << std::endl;
  return 0;
}