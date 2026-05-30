#include "inc/iter.hpp"

template <typename T>
void	testFunction(T &t)
{
	std::cout << t << std::endl;
}

int	main(void)
{
	try
	{
		int	array[6] = { 0, 1, 2, 3, 4, 5 } ;
		std::cout << "TEST 00 INT ARRAY" << std::endl;
		::iter(array, 6, testFunction);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		char	array[6] = { 'a', 'b', 'c', 'd', 'e', 'f' } ;
		std::cout << "TEST 01 CHAR ARRAY" << std::endl;
		::iter(array, 6, testFunction);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
		try
	{
		std::string	array[6] = { "Hello", "World", "this", "is", "a", "test." } ;
		std::cout << "TEST 02 STRING ARRAY" << std::endl;
		::iter(array, 6, testFunction);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
