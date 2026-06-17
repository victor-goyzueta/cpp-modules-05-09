#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <list>

int	main()
{
	std::cout << "----- TEST VECTOR -----" << std::endl;

	std::vector<int> v;
	for (int  i = 0; i < 10; i++)
		v.push_back(i * 10);
	
	try
	{
		std::vector<int>::iterator it = easyfind(v, 30);
		std::cout << "Value found: " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Value not found: " << e.what() << std::endl;
	}
	
	try
	{
		std::vector<int>::iterator it = easyfind(v, 999);
		std::cout << "Value found: " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Value not found: " << e.what() << std::endl;
	}
	
	std::cout << std::endl << "----- TEST LIST -----" << std::endl;


	std::list<int> l;
	for (int i = 0; i < 5; i++)
		l.push_back(i * 3);

	try
	{
		std::list<int>::iterator it = easyfind(l, 6);
		std::cout << "Value found: " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Value not found: " << e.what() << std::endl;
	}

	return 0;	
}
