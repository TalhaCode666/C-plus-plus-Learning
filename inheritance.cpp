#include <iostream>
#include <string>
#include <string_view> // helps us avoid string copies..

/*
https://www.youtube.com/watch?v=8jLOx1hD3_o&t=665s
timestamp: 24:26:36

*/

class Person
{
  friend std::ostream &operator<<(std::ostream &out, const Person &person)
  {
    out << "Person [" << person.first_name << " " << person.last_name << " ]";
    return out;
  }
  /*
  The << symbol is the stream insertion operator. By defining operator<<, you are teaching C++ how to convert your custom Player class into a stream of text.

  1) std::ostream &: This is a reference to the output stream (like std::cout or a file stream). It is passed by reference so the function can write directly to it.
  2) const Player &player: This is the object you want to print. It is passed by const reference to avoid making a slow copy of the object and to guarantee the function won't accidentally modify the player's data.

  By putting the keyword friend inside the Player class definition, you are giving this specific function special permission to directly access the private and protected members of Player. This allows the function to print the player's internal stats without needing public getter methods

  */
public:
  Person() = default;
  Person(std::string_view first_name, std::string_view last_name) : first_name(first_name), last_name(last_name) {}

  std::string_view get_first_name() const
  {
    return this->first_name;
  }

  std::string_view get_last_name() const
  {
    return this->last_name;
  }

  void set_first_name(std::string_view fn)
  {
    this->first_name = fn;
  }

  void set_last_name(std::string_view ln)
  {
    this->last_name = ln;
  }

  // ~Person();

private:
  std::string first_name{"N/A"};
  std::string last_name{"N/A"};
};

class Player : public Person // extending player class with Person class with Public memebers
{
  friend std::ostream &operator<<(std::ostream &out, const Player &player)
  {
    out << "[" << "Game: " << player.game_name
        << " -- First Name: " << player.get_first_name()
        << " -- Last Name: " << player.get_last_name() << " ]";
    return out;
  }

public:
  Player() = default;
  Player(std::string game_name) : game_name(game_name) {}
  // ~Player();

private:
  std::string game_name{"N/A"};
};

int main()
{
  Player p1("GTA");
  p1.set_first_name("Ray");
  p1.set_last_name("Gunn");
  std::cout << "Player: " << p1 << std::endl;

  std::cout << "================================" << std::endl;
  std::cout << "Program worked successfully!" << std::endl;
  return 0;
}