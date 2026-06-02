#include "inc/Array.hpp"

#include <iostream>

int main()
{

	try
	{
		Array<int> test;

		std::cout << test.size() << std::endl;
		std::cout << test[0];
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Array<float> test(5);

		std::cout << test.size() << std::endl;
		for (unsigned int i = 0; i < 5; i++) {
			std::cout << test[i] << std::endl;
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Array<char> test(3);

		test[0] = ':';
		test[1] = ')';

		Array<char> copy(test);

		copy[1] = '(';

		std::cout << test[0] << test[1] << std::endl;
		std::cout << copy[0] << copy[1] << std::endl;
	} 
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Array<int> test(2);

		test[6] = 1;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
