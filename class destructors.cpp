#include <iostream>
#include <string>
#include <string_view> // helps us avoid string copies..

/*
https://www.youtube.com/watch?v=8jLOx1hD3_o&t=665s
timestamp: 22:11:03

*/

class Dog
{
public:
  Dog() = default;
  Dog(std::string_view name_param, std::string_view breed_param, int p_age_param);
  ~Dog();

private:
  std::string name;
  std::string breed;
  int *p_age{nullptr};
};

Dog::Dog(std::string_view name_param, std::string_view breed_param, int p_age_param)
{
  this->name = name_param;
  this->breed = breed_param;
  this->p_age = new int{p_age_param}; // assigning int address space to it.
  std::cout << "Dog constructor called for: " << this->name << std::endl;
}

Dog::~Dog()
{
  delete p_age;
  std::cout << "Dog destructor called for: " << this->name << std::endl;
}

void rand_fuction()
{
  // Dog my_dog("Fluffy", "Shepherd", 2);
  Dog* p_dog= new Dog("Luffy", "Shepherd", 5);
  delete p_dog;

  /*
  when making heap class calls, you've to manually call the delete to invoke, destructors; otherwise, it won't call itself. to test, you can comment delete p_dog; line.
  */
}

int main()
{
  rand_fuction();
  std::cout << "================================" << std::endl;
  std::cout << "Program worked successfully!" << std::endl;
  return 0;
}