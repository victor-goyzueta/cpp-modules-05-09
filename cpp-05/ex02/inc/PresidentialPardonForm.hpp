#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm( const std::string& target );
		PresidentialPardonForm( const PresidentialPardonForm& copy );
		~PresidentialPardonForm();

		PresidentialPardonForm& operator=( const PresidentialPardonForm& other );

		void	execute( Bureaucrat const& executor ) const;
		void	action() const;
};

#endif
