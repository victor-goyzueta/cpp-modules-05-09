#include "../inc/Intern.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

#include <iostream>
#include <string>

Intern::Intern() {}

Intern::Intern( const Intern& copy )
{
	(void)copy;
}

Intern& Intern::operator=( const Intern& other )
{
	(void)other;
	return (*this);
}

Intern::~Intern() {}

AForm* Intern::makeForm( std::string const& name, std::string const& target )
{
	std::string knowTypes[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	for (size_t i = 0; i < 3; i++)
	{
		if (knowTypes[i] == name)
		{
			switch (i)
			{
				case 0:
					return new ShrubberyCreationForm(target);
				case 1:
					return new RobotomyRequestForm(target);
				case 2:
					return new PresidentialPardonForm(target);
				default:
					throw InvalidFormException();
			}
		}
	}
	std::cerr << "Intern: unknown form name \"" << name << "\"" << std::endl;
	return (NULL);
}

const char *Intern::InvalidFormException::what() const throw()
{
	return ("Form doesn't exist");
}
