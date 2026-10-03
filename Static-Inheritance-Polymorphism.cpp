#include <iostream>
#include <string_view>

/*
https://www.youtube.com/watch?v=8jLOx1hD3_o&t=665s
timestamp: 28:33:03
*/

class Shape
{
public:
  Shape() = default;
  Shape(std::string_view description_param) : description(description_param)
  {
    // Increments Shape::count
    ++count;
  }

  void draw() const
  {
    std::cout << "Shape::draw() called for: " << description << std::endl;
  }
  // add 'virtual' so that the derived class can use 'override'
  virtual int get_count() const
  {
    return count;
  }

  virtual ~Shape() = default;

  static int count;

protected:
  std::string description;
};

class Ellipse : public Shape
{
public:
  Ellipse() { count++; }
  Ellipse(double x_radius, double y_radius, std::string_view description_param) : Shape(description_param), x_radius(x_radius), y_radius(y_radius)
  {
    // Increments Ellipse::count
    ++count;
  }

  void draw() const
  {
    std::cout << "Ellipse::draw_impl() called for: " << description
              << " [Radius: " << x_radius << "x" << y_radius << "]" << std::endl;
  }

  virtual int get_count() const override
  {
    return count;
  }

  static int count;

  ~Ellipse() = default;

private:
  double x_radius{};
  double y_radius{};
};

// Definitions for static variables
int Shape::count = 0;
int Ellipse::count = 0;

int main()
{
  Shape shape1("Shape1");
  // std::cout << "shape count: " << Shape::count << std::endl;

  Shape shape2("Shape2");
  // std::cout << "shape count: " << Shape::count << std::endl;

  Shape shape3("Shape3");
  // std::cout << "shape count: " << Shape::count << std::endl;

  Ellipse ellipse1(10, 12, "Ellipse1");
  // std::cout << "shape count: " << Shape::count << std::endl;
  // std::cout << "Ellipse count: " << Ellipse::count << std::endl;

  std::cout << "-------------------------" << std::endl;

  // shape polymorphism
  Shape *shapes[]{&shape1, &ellipse1};
  for (auto &s : shapes)
  {
    std::cout << "count: " << s->get_count() << std::endl;
  }

  std::cout << "-------------------------" << std::endl;
  return 0;
}