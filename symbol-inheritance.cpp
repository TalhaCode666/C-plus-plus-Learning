#include <iostream>

/*
https://www.youtube.com/watch?v=8jLOx1hD3_o&t=665s
timestamp: 26:21:03
*/
class Parent
{
public:
  Parent() = default;
  Parent(int number_var_param) : number_var(number_var_param) {}

  void print_info() const
  {
    std::cout << "Parent Value is: " << number_var << std::endl;
  }

  ~Parent()=default;

protected:
  int number_var{100};
};

class Child: public Parent
{
public:
  Child() = default;
  Child(int number_var_param) : number_var(number_var_param) {}

  void print_info() const
  {
    std::cout << "Child Value is: " << number_var << std::endl;
  }
    void show_values() const
  {
    std::cout << "Child Value is: " << number_var << std::endl;
    std::cout << "Parent value inside Child class is: " << Parent::number_var << std::endl;
  }
  /*
  Parent::number_var -- this lets break the default behavoir and lets user to access the same named value from the parent instead of taking from itself. 
  */

  ~Child()=default;
  
protected:
  int number_var{1000};
};

int main()
{
  Child Child(33);
  Child.print_info(); // calls method from child.
  Child.Parent::print_info(); // calls method from Parent.
  std::cout << "---------------------" << std::endl;
  
  Child.show_values();
  std::cout << "---------------------" << std::endl;
  return 0;
}

/*
Child.Parent::print_info(); -- this syntax also works. doesn't need any defination or defining. it just goes directly to the parent and uses its function.

or you can build something custom, like Child.show_values(); -- here Parent::number_var is being called to print value. btw, you can do Parent::print_info() inside class as well.
*/