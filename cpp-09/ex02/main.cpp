#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
	{
		std::cerr << "Error: Usage: ./PmergeMe <positive integers>." << std::endl;
		return 1;
	}

	try
	{
		PmergeMe::process(argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
