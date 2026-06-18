#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <list>

template <typename T>
void	printContainer( const T& container )
{
	typename T::const_iterator it = container.begin();
	typename T::const_iterator end = container.end();

	for (; it != end; ++it)
	{
		std::cout << "[" << *it << "]";

	}
	std::cout << std::endl;
}

int	main()
{
	std::cout << "----- TEST VECTOR -----" << std::endl;

	std::vector<int> v;
	for (int  i = 0; i < 10; i++)
		v.push_back(i * 10);
	
	printContainer(v);
	
	try
	{
		std::vector<int>::iterator it = easyfind(v, 30);
		std::cout << "Value found: " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	try
	{
		std::vector<int>::iterator it = easyfind(v, 29);
		std::cout << "Value found: " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	std::cout << std::endl << "----- TEST LIST -----" << std::endl;


	std::list<int> l;
	for (int i = 0; i < 5; i++)
		l.push_back(i * 3);

	printContainer(l);

	try
	{
		std::list<int>::iterator it = easyfind(l, 6);
		std::cout << "Value found: " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try
	{
		std::list<int>::iterator it = easyfind(l, 4);
		std::cout << "Value found: " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "----- TEST DEQUE -----" << std::endl;

	std::deque<int> d;
	for (int i = 0; i < 5; i++)
		d.push_back(i * 2);
	
	printContainer(d);

	try
	{
		std::deque<int>::iterator it = easyfind(d, 8);
		std::cout << "Value found: " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try
	{
		std::deque<int>::iterator it = easyfind(d, 3);
		std::cout << "Value found: " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "----- TEST CONST CONTAINER -----" << std::endl;

	std::vector<int> tmp;
	for (int i = 0; i < 10; i++)
		tmp.push_back(i);

	const std::vector<int> vec = tmp;

	printContainer(vec);

	try
	{
		std::vector<int>::const_iterator it = easyfind(vec, 7);
		std::cout << "Found value: " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try
	{
		std::vector<int>::const_iterator it = easyfind(vec, -1);
		std::cout << "Found value: " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;	
}
