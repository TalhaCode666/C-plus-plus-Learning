#include <iostream>
#include <string>
#include <string_view> // helps us avoid string copies..

/*
https://www.youtube.com/watch?v=8jLOx1hD3_o&t=665s
timestamp: 24:46:59

*/

#include <iostream>
#include <string>
#include <string_view>

class Person
{
  friend std::ostream &operator<<(std::ostream &out, const Person &person)
  {
    out << "Person [" << person.first_name << " " << person.last_name << " ]";
    return out;
  }

public:
  Person() = default;
  Person(std::string_view first_name, std::string_view last_name) : first_name(first_name), last_name(last_name) {}

  std::string_view get_first_name() const { return this->first_name; }
  std::string_view get_last_name() const { return this->last_name; }
  void set_first_name(std::string_view fn) { this->first_name = fn; }
  void set_last_name(std::string_view ln) { this->last_name = ln; }

protected:
  size_t age{};

private:
  std::string first_name{"N/A"};
  std::string last_name{"N/A"};
};

// 1. CHANGED: Inherit privately so everything from Person is hidden by default
class Player : private Person 
{
  friend std::ostream &operator<<(std::ostream &out, const Player &player)
  {
    out << "[" << "Game: " << player.game_name
        << " -- First Name: " << player.get_first_name() // Works internally
        << " -- Last Name: " << player.get_last_name() 
        << " -- Age: " << player.age << " ]";
    return out;
  }

public:
  Player() = default;
  Player(std::string game_name) : game_name(game_name) {}

  // 2. THE CORE TRICK: Rescues 'age' from private inheritance and makes it public
  using Person::age; 
  
  // Expose these methods manually since private inheritance hid them from main()
  using Person::set_first_name;
  using Person::set_last_name;
  using Person::get_first_name;
  using Person::get_last_name;

private:
  std::string game_name{"N/A"};
};

int main()
{
  Player p1("GTA");
  p1.set_first_name("Ray");
  p1.set_last_name("Gunn");
  
  // 3. PROOF: You can directly assign 'age' in main because of the using keyword!
  p1.age = 25; 

  std::cout << "Player: " << p1 << std::endl;

  std::cout << "================================" << std::endl;
  std::cout << "Program worked successfully!" << std::endl;
  return 0;
}
