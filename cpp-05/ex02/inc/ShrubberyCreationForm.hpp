#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm( std::string& target );
		ShrubberyCreationForm( const ShrubberyCreationForm& copy );
		~ShrubberyCreationForm();

		ShrubberyCreationForm& operator=( const ShrubberyCreationForm& other );
};

#endif
