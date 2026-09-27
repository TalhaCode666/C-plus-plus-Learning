#include <iostream>
#include <string>

/*
https://www.youtube.com/watch?v=8jLOx1hD3_o&t=665s
timestamp: 24:26:36

*/

class Base {
protected:
    int age{0}; // Protected: Hidden from main(), visible to Derived
};

// Private inheritance hides EVERYTHING from the outside world by default
class Derived : private Base {
public:
    // EXCEPTION: Bring ONLY 'age' into the public scope of Derived
    using Base::age; 

    void set_age(int a) { 
        age = a; // Private inheritance still allows internal access
    }
};

int main() {
    Derived d;

    // 1. This WORKS because 'using Base::age' made it public in Derived!
    d.age = 25; 
    std::cout << "Age accessed directly: " << d.age << "\n";

    // 2. This would FAIL to compile if uncommented:
    // d.set_age(30); // (This works, but emphasizes that 'age' is public)
    
    // 3. This will FAIL to compile because Base is inherited privately:
    // Base* ptr = &d; // Error: Cannot cast Derived* to private Base*

    return 0;
}
