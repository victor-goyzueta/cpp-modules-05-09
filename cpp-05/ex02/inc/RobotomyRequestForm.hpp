#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm( std::string& target );
		RobotomyRequestForm( const RobotomyRequestForm& copy );
		~RobotomyRequestForm();

		RobotomyRequestForm& operator=( const RobotomyRequestForm& other );

		void	execute( Bureaucrat const& executor ) const;
		void	action() const;
};

#endif
