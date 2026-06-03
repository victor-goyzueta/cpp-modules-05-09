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

AForm	*Intern::makeForm(std::string const& formName, std::string const& target)
{
	std::string names[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	AForm *(Intern::*funcs[])(std::string const&) =
		{ &Intern::createShrubbery, &Intern::createRobotomy, &Intern::createPresidential };
	for (size_t i = 0; i < 3; i++)
	{
		if (formName == names[i])
		{
			AForm *form = (this->*funcs[i])(target);
			std::cout << "Intern creates " << formName << std::endl;
			return (form);
		}
	}
	throw InvalidFormException();
}

AForm* Intern::createShrubbery(std::string const& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::createRobotomy(std::string const& target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::createPresidential(std::string const& target)
{
	return (new PresidentialPardonForm(target));
}

const char *Intern::InvalidFormException::what() const throw()
{
	return ("Form doesn't exist");
}
