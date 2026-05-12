#include "inc/Bureaucrat.hpp"

#include <iostream>
#include <string>

int main()
{
	try
	{
		Bureaucrat a;
		Bureaucrat b("Bob", 1);
		Bureaucrat c(b);

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;

		a = c;

		std::cout << a << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		Bureaucrat	b1("Alice", 1);
		std::cout << b1 << std::endl;

		b1.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	b2("Bob", 151);
		std::cout << b2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	b3("Foo", 2);
		std::cout << b3 << std::endl;

		b3.incrementGrade();

		std::cout << b3 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}
