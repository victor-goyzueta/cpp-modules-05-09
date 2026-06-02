#include "iter.hpp"

template <typename T>
void	printValue(T &value)
{
	std::cout << value << std::endl;
}

template <typename T>
void	increment(T &n)
{
	n += 1;
}

template <typename T>
void	toUpper(T &c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
}

template <typename T>
void	password(T &s)
{
	for (size_t i = 0; s[i]; i++)
		s[i] = '*';
}

int	main(void)
{
	{
		int	array[6] = { 0, 1, 2, 3, 4, 5 } ;
		std::cout << "----- TEST INT ARRAY -----" << std::endl;
		::iter(array, 6, printValue);
		::iter(array, 6, increment);
		std::cout << "----- increment function -----" << std::endl;
		::iter(array, 6, printValue);
	}
	{
		char	array[6] = { 'a', 'b', 'c', 'd', 'e', 'f' } ;
		std::cout << "----- TEST CHAR ARRAY -----" << std::endl;
		::iter(array, 6, printValue);
		::iter(array, 6, toUpper);
		std::cout << "----- toUpper function -----" << std::endl;
		::iter(array, 6, printValue);
	}
	{
		std::string	array[6] = { "hello", "world", "this", "is", "a", "test." } ;
		std::cout << "----- TEST STRING ARRAY -----" << std::endl;
		::iter(array, 6, printValue);
		::iter(array, 6, password);
		std::cout << "----- password function -----" << std::endl;
		::iter(array, 6, printValue);
	}
	return (0);
}
