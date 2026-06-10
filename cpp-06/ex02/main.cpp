#include "inc/Base.hpp"

#include <iostream>
#include <ctime>

int	main()
{
	std::srand(std::time(0));

	Base* ptr = generate();

	std::cout << "identify(Base *): ";
	identify(ptr);

	std::cout << "identify(Base &): ";
	identify(*ptr);
	
	delete ptr;
	return 0;
}
