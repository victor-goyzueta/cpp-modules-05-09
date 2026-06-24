#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

Base::~Base() {}

Base*	generate( void )
{
	int	r = std::rand() % 3;

	if (r == 0)
	{
		std::cout << "generate() created: A" << std::endl;
		return new A;
	}
	else if (r == 1)
	{
		std::cout << "generate() created: B" << std::endl;
		return new B;
	}
	else
	{
		std::cout << "generate() created: C" << std::endl;
		return new C;
	}
}

void	identify( Base* p )
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void	identify( Base& p )
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}

	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}

	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}

	std::cout << "Unknown type" << std::endl;
}
