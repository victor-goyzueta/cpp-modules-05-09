#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>

# include "AForm.hpp"

class PresidentialPardonRequestForm : public AForm
{
	public:
		PresidentialPardonRequestForm();
		PresidentialPardonRequestForm( std::string& target );
		PresidentialPardonRequestForm( const PresidentialPardonRequestForm& copy );
		~PresidentialPardonRequestForm();

		PresidentialPardonRequestForm& operator=( const PresidentialPardonRequestForm& other );

		void	execute( Bureaucrat const& executor ) const;
		void	action() const;
};

#endif
