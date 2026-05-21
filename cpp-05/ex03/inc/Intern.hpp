#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>

# include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern( const Intern& copy );
		~Intern();

		Intern& operator=( const Intern& other );

		AForm*	makeForm( std::string const& name, std::string const& targetForm );

		class InvalidFormException : public std::exception
		{
			const char* what() const throw();
		};
};

#endif