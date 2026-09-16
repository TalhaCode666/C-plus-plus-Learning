#include <iostream>
#include <cctype> // strings manipulation lib
#include <string>
#include <typeinfo> // checks types of variables

/*
https://www.youtube.com/watch?v=8jLOx1hD3_o&t=665s
timestamp: 16:49:01

*/

// function overloading in practice through our func 'max()'
int max(int a, int b)
{
  return (a > b) ? a : b;
}

double max(double a, double b)
{
  return (a > b) ? a : b;
}

double max(int a, double b)
{
  return (a > b) ? a : b;
}

// this is return by refrence version but for strings, and it return addresess, and it can be dangling pointers. Be careful!

std::string_view max(std::string_view a, std::string_view b)
{
  return (a.length() >= b.length()) ? a : b;
}

int main()
{
  int IntVal1{3};
  int IntVal2{13};

  auto Overloadresult1 = max(IntVal1, IntVal2);
  std::cout << "Result: " << Overloadresult1 << " -- " << typeid(Overloadresult1).name() << std::endl;

  double DVal1{13.6};
  double DVal2{68.6};
  auto Overloadresult2 = max(DVal1, DVal2);
  std::cout << "Result: " << Overloadresult2 << " -- " << typeid(Overloadresult2).name() << std::endl;

  std::string str_view1{"Hello"};
  std::string str_view2{"World"};
  auto Overloadresult3 = max(str_view1, str_view2);
  std::cout << "Result: " << Overloadresult3 << " -- " << typeid(Overloadresult3).name() << std::endl;

  /*
  mixed args overload, and it still works; would work with more args, types, and even positional
  changes.
  */

  auto Overloadresult4 = max(IntVal2, DVal1);
  std::cout << "Result: " << Overloadresult4 << " -- " << typeid(Overloadresult4).name() << std::endl;

  std::cout << "================================" << std::endl;
  std::cout << "Program worked successfully!" << std::endl;
  return 0;
}