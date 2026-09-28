#include <iostream>
#include "person.h"
#include "engineer.h"
#include "civilengineer.h"

/*
https://www.youtube.com/watch?v=8jLOx1hD3_o&t=665s
timestamp: 25:51:53
*/

int main()
{

	std::cout << "---------------------" << std::endl;
	CivilEngineer civil_eng1("John Travolta", 51, "Tiny Dog 42St#89", 31, "Road Strength");
	std::cout << "civil_eng1 : " << civil_eng1 << std::endl;
	std::cout << "---------------------" << std::endl;
	
	// using custom copy constructors we copied 1-1.. by default, compiler can do as well..
	CivilEngineer civil_eng2(civil_eng1);
	std::cout << "civil_eng2 : " << civil_eng2 << std::endl;
	std::cout << "---------------------" << std::endl;

	return 0;
}