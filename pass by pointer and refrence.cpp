#include <iostream>
#include <cctype> // strings manipulation lib
#include <string>

/*
https://www.youtube.com/watch?v=8jLOx1hD3_o&t=665s
timestamp: 16:17:57

*/

// pass by pointer
void SayAge(int *age)
{
  ++(*age);
}

// pass by refrence
void EnterBar(int &age)
{
  if (age >= 18)
  {
    ++age;
  }
  else
  {
    --age;
  }
}

void max_str(const std::string &input1, const std::string &input2, std::string &output)
{

  output = (input1.length() > input2.length()) ? input1 : input2;
}

void max_double(const double &firstval, const double &Secval, double *output)
{

  // Safety check: only write if the pointer actually points to something
  if (output != nullptr)
  {
    *output = (firstval > Secval) ? firstval : Secval;
  }
}

int main()
{

  /*
  we made a function which doesn't take the value itself but points to its orignal mem, so everything
  happens in place.. if something is done in the function to the value, it also reflects in the
  orignal passed location/variable. how? by using '&' and '*'
 */

  int CurrentAge{24};

  std::cout << "Your age before is: " << CurrentAge
            << " -- Address: " << &CurrentAge << std::endl;

  SayAge(&CurrentAge);

  std::cout << "Your age after is: " << CurrentAge
            << " -- Address: " << &CurrentAge << std::endl;

  std::cout << "================================" << std::endl;

  /*
we made a function which doesn't take the value itself but refrences/alias of orignal mem, so everything happens in place.. if something is done in the function to the value, it also reflects in the orignal variable. how? (int &age) is passed as argument in function.

now, everything done with it also changes everything. and it is less messy than pointers.
*/

  std::cout << "Before entering bar is: " << CurrentAge
            << " -- Address: " << &CurrentAge << std::endl;

  EnterBar(CurrentAge);

  std::cout << "Afer entering bar is: " << CurrentAge
            << " -- Address: " << &CurrentAge << std::endl;

  std::cout << "================================" << std::endl;

  /* we wrote a function that takes 2 strings, and one result variable, compares their lenghts
  and then stores it into the result variable.. all done by the pass by refrence tecnique. */

  std::string a{"Hello World!"};
  std::string b{"Hello Earthlings!"};
  std::string result;

  max_str(a, b, result);
  std::cout << "Result variable contains: " << result << std::endl;

  std::cout << "================================" << std::endl;

  double firstval{32.1};
  double Secval{31.9};
  double Numbresult{};

  max_double(firstval, Secval, &Numbresult);
  std::cout << "Result contains: " << Numbresult << std::endl;

  std::cout << "================================" << std::endl;
  std::cout << "Program worked successfully!" << std::endl;
  return 0;
}