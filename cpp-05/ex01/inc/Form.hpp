#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_gradeToSign;
		int const			_gradeToExecute;

	public:
		Form();
		Form( std::string name, int gradeToSign, int gradeToExecute );
		Form( const Form& copy );
		~Form();

		Form& operator=( const Form& form );

		std::string	getName() const;
		bool		getIsSigned() const;
		int 		getGradeToSign() const;
		int			getGradeToExecute() const;

		void		beSigned( Bureaucrat& bureaucrat );

		class GradeTooHighException : public std::exception
		{
			const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
