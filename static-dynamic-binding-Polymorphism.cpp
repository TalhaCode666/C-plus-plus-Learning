#include <iostream>
#include <string_view>
#include <string>

/*
https://www.youtube.com/watch?v=8jLOx1hD3_o&t=665s
timestamp: 27:45:42
*/

class Shape
{
public:
  Shape() = default;
  Shape(const std::string_view &description) : shape_description(description) {}

  // 1. Virtual destructor is essential for polymorpic base classes
  virtual ~Shape() = default;

  // 2. Added 'virtual' keyword here
  virtual void draw() const
  {
    std::cout << "Shape::draw() called. Drawing: " << shape_description << std::endl;
  }

protected:
  std::string shape_description{""};
};

class Oval : public Shape
{
public:
  Oval() = default;
  // Properly initialize the base class constructor
  Oval(double x_radius, double y_radius, const std::string_view &description)
      : Shape(description), x_radius(x_radius), y_radius(y_radius) {}
  ~Oval() override = default;

  // 3. Added 'override' keyword for safety
  virtual void draw() const override
  {
    std::cout << "Oval::draw() called. Drawing: " << shape_description
              << " with x_radius: " << get_x_radius()
              << " and y_radius: " << get_y_radius() << std::endl;
  }

protected:
  double x_radius{};
  double y_radius{};

  double get_x_radius() const
  {
    return x_radius;
  }

  double get_y_radius() const
  {
    return y_radius;
  }
};

class Circle : public Oval
{
public:
  Circle() = default;
  // Properly initialize the base class constructor
  Circle(double radius, const std::string_view &description)
      : Oval(radius, radius, description) {}
  ~Circle() override = default;

  virtual void draw() const override
  {
    std::cout << "Circle::draw() called. Drawing: " << shape_description
              << " with x_radius: " << get_x_radius() << std::endl;
  }
};

int main()
{
  Shape shape1("Shape1");
  Oval oval1(2.0, 3.5, "oval1");
  Circle Circle1(2.0, "Circle1");

  Shape *shape_ptr = &shape1;
  shape_ptr->draw(); // Calls Shape::draw()

  shape_ptr = &oval1;
  shape_ptr->draw(); // calls Oval::draw()

  shape_ptr = &Circle1;
  shape_ptr->draw(); // calls Circle::draw()
  std::cout << "---------------------" << std::endl;

  // another way to test polymorphism, deciding on runtime which draw() to run based on base class.
  Shape *shape_collection[]{&shape1, &oval1, &Circle1};
  for (Shape *s_ptr : shape_collection)
  {
    std::cout << "sizeof(*s_ptr): " << sizeof(*s_ptr) << " bytes." << std::endl;
    s_ptr->draw();
  }
  std::cout << "---------------------" << std::endl;

  std::cout << "sizeof(Shape): " << sizeof(Shape) << " bytes." << std::endl;
  std::cout << "sizeof(Oval): " << sizeof(Oval) << " bytes." << std::endl;
  std::cout << "sizeof(Circle): " << sizeof(Circle) << " bytes." << std::endl;

  std::cout << "---------------------" << std::endl;

  /*
  Slicing - derived object being assigned to base object would result in stripping the un-needed. compiler strips unnessary dynamic ptr and only keeping what is neeeded. How? well, 'shape2' object is initiated  with class 'Shape' class, and we're assigning an object which is inheriting and linking back to Oval, circle, and shape classess. We only need the shape part.

  Plus, it'll save memeory from dynamic binding. The compiler would only point to the base class, won't do polymorphism. It'll slice off the rest; that's why ptr/refrencing is used.

  Polymorphism via virtual functions was made for base ptrs that are managing derived objects.

  */
  Shape shape2 = Circle1;
  shape2.draw();
  std::cout << "sizeof(shape2): " << sizeof(shape2) << " bytes." << std::endl;

  std::cout << "---------------------" << std::endl;
  return 0;
}

/*
'virtual' keyword is doing the dynamic binding; if removed, and 'override' is also taken off the whole setup would become static. Meaning the base class would be called ALWAYS, instead of looking at the pointer being pointed at a type of derived class..

with dynamic binding - it gives us power to "Don't look at the type of the base pointer; look at the type of the object which is being pointed/refrenced. "
*/