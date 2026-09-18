#include <iostream>
#include <cmath>
#include <typeinfo> // type checker

/*
https://www.youtube.com/watch?v=8jLOx1hD3_o&t=665s
timestamp: 17:40:14

*/

auto lamba_func = []()
{
  std::cout << "Assigned lambada function is called." << std::endl;
};

auto SumMultipler = [](double a, double b)
{
  return std::pow(a + b, b);
};

auto SumOf = [](int a, double b) -> double
{
  return a + b;
};

int main()
{

  // ghost/lambda func is directly called.
  []()
  {
    std::cout << "ghost lambada function is called." << std::endl;
  }();

  // Assigned lambada function is called
  lamba_func();

  // Passed value lambada function is called
  std::cout << "SumMultipler is: " << SumMultipler(2, 5) << std::endl;

  // lambada function and static return type is called
  int IntVal1{3};
  double IntVal2{13.5};

  std::cout << "SumOf is: " << SumOf(IntVal1, IntVal2) << " -- " << typeid(SumOf(IntVal1, IntVal2)).name() << std::endl;

  std::cout << "================================" << std::endl;

  // getting the outside scope/context which is not passed as parameter, but want to use.. the value would be the copy of it..

  [IntVal1, IntVal2]()
  {
    std::cout << "Out-of-context result: " << IntVal1 * IntVal2 << std::endl;
  }();

  // refrencing the orignal out scope address directly instead of making copies.
  auto Reflambda = [&IntVal1]()
  {
    std::cout << "Inner Value: " << IntVal1 << " -- Address: " << &IntVal1 << std::endl;
  };

  for (size_t i = 0; i < 2; ++i)
  {
    /* code */
    std::cout << "Outer Value: " << IntVal1 << " -- Address: " << &IntVal1 << std::endl;
    Reflambda();
    ++IntVal1;
  }

  std::cout << "================================" << std::endl;
  std::cout << "Program worked successfully!" << std::endl;
  return 0;
}