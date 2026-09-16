#include <iostream>
#include <cctype> // strings manipulation lib
#include <string>

/*
https://www.youtube.com/watch?v=8jLOx1hD3_o&t=665s
timestamp: 14:52:28

*/

void AgeChck(size_t age)
{

  if (age >= 18)
  {
    std::cout << "You're of age!" << std::endl;
  }
  else
  {
    std::cout << "You're underage!" << std::endl;
  }
}

double NumbMultipler(double a, double b)
{
  return ((++a) * (++b));
}

int main()
{

  AgeChck(13);
  double a{10.1};
  double b{10.1};

  //  dispite incrementing values, it won't change orignal variables, because it is a copy of them.
  std::cout << "Result: " << NumbMultipler(a, b)
            << " -- Value of a/b: " << a << " -- " << b << std::endl;

  // a loop which checks if by function that age is over 18.
  for (size_t i{10}; i < 20; ++i)
  {
    /* code */
    AgeChck(i);
  }

  std::cout << "================================" << std::endl;
  std::cout << "Program worked successfully!" << std::endl;
  return 0;
}