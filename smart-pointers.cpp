#include <iostream>
#include <memory>
#include <utility> // For std::move

/*
https://www.youtube.com/watch?v=e2LMAgoqY_k
*/

class MyClass
{
public:
  MyClass()
  {
    std::cout << "Constructor invoked!" << std::endl;
  }

  ~MyClass()
  {
    std::cout << "Destructor invoked!" << std::endl;
  }
};

int main()
{
  std::cout << "============= unique ptr! =============" << std::endl;
  // unique ptr, that can't be shared. We have the ownership
  // std::unique_ptr<int> unPtr1(new int(33));
  std::unique_ptr<int> unPtr1 = std::make_unique<int>(25);
  std::cout << "Unique(25): " << *unPtr1 << std::endl;

  // std::move transfers ownership. unPtr1 becomes null, unPtr2 takes the heap memory.
  std::unique_ptr<int> unPtr2 = std::move(unPtr1);
  std::cout << "Move(unPtr1): " << *unPtr2 << std::endl;

  if (unPtr1)
  {
    /* if it is not null ptr, print */
    std::cout << "Unique(25): " << *unPtr1 << std::endl;
  }
  else
  {
    /* if it is null ptr, print */
    std::cout << "Unique(unPtr1) has become null ptr, can't print." << std::endl;
  }

  std::cout << "============= shared ptr! =============" << std::endl;

  // shared ptr, that can be shared. multiple ownership.
  std::shared_ptr<MyClass> sPtr1 = std::make_shared<MyClass>();
  std::cout << "Shared sPtr1.use_count(): " << sPtr1.use_count() << std::endl;

  {
    std::shared_ptr<MyClass> sPtr2 = sPtr1;
    std::cout << "Shared sPtr1.use_count(): " << sPtr1.use_count() << std::endl;
  }

  std::cout << "Shared sPtr1.use_count(): " << sPtr1.use_count() << std::endl;

  std::cout << "============= weak ptr! =============" << std::endl;

  // weak_ptr tracks sPtr1 without increasing the reference count.
  std::weak_ptr<MyClass> wPtr1;
  {
    std::cout << "--- Inner Scope Starts ---" << std::endl;
    std::shared_ptr<MyClass> sPtr3 = std::make_shared<MyClass>();
    wPtr1 = sPtr3;
    std::cout << "sPtr3.use_count(): " << sPtr3.use_count() << std::endl;
  } // <-- sPtr3 dies here, dropping the Strong Count to 0!

  std::cout << "--- Back in Main Scope ---" << std::endl;
  // 1. Check if the object is dead
  if (wPtr1.expired())
  {
    std::cout << "The object is dead in main!" << std::endl;
  }
  else
  {
    std::cout << "The object is still alive!" << std::endl;
  }

  return 0;
}

// main() ends: sPtr1 goes out of scope, count hits 0, Destructor is called!