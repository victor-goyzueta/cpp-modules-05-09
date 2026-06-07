#include "inc/ScalarConverter.hpp"

#include <iostream>

int	main( int argc, char** argv )
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./ex00 <literal>" << std::endl;
		return (1);
	}
	else
	{
		try
		{
			ScalarConverter::convert(argv[1]);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			return (1);
		}
	}
	return (0);
}
