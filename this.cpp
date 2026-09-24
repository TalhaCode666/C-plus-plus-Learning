#include <iostream>
#include <string>
#include <string_view> // helps us avoid string copies..

/*
https://www.youtube.com/watch?v=8jLOx1hD3_o&t=665s
timestamp: 22:33:35

*/

class Dog
{
public:
  Dog() = default;
  Dog(std::string_view name_param, std::string_view breed_param, int p_age_param);

  Dog &set_dog_name(std::string_view name_param);
  Dog &set_dog_breed(std::string_view breed_param);
  Dog &set_dog_age(int age_param);
  Dog &print_info();

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

// Return *this to pass the current object back
Dog &Dog::set_dog_name(std::string_view name_param)
{
  this->name = name_param;
  return *this;
}

Dog &Dog::set_dog_breed(std::string_view breed_param)
{
  this->breed = breed_param;
  return *this;
}

Dog &Dog::set_dog_age(int age_param)
{
  if (this->p_age) // if Is(False)/NOT(True) null 
  {
    *(this->p_age) = age_param;
  }
  else
  {
    // The memory does NOT exist yet, so make it and assign value.
    this->p_age = new int{age_param};
  }
  return *this;
}

Dog &Dog::print_info()
{
  // Safely check if pointer exists before dereferencing to prevent crashes
  int age_val = (this->p_age) ? *(this->p_age) : 0;

  std::cout << "Dog (" << this << "): "
            << "[Name: " << name
            << " Breed: " << breed
            << " Age: " << *(p_age) << "]" << std::endl;
  return *this;
}

Dog::~Dog()
{
  delete p_age;
  std::cout << "Dog destructor called for: " << this->name << std::endl;
}

int main()
{
  // Stack object chaining using '.'
  Dog my_dog;
  my_dog.set_dog_name("Fluffy").set_dog_breed("Shepherd").set_dog_age(3).print_info();

  // Heap object pointer chaining using '->' then '.'
  Dog *p_dog = new Dog();
  p_dog->set_dog_name("Luffy").set_dog_breed("Husky").set_dog_age(5).print_info();
  delete p_dog;

  std::cout << "================================" << std::endl;
  std::cout << "Program worked successfully!" << std::endl;
  return 0;
}

/*
this keyword mixed with object chainning concept.
*/