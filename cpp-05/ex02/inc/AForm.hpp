#ifndef AForm_HPP
# define AForm_HPP

# include <iostream>
# include <string>

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_gradeToSign;
		int const			_gradeToExecute;
		std::string const	_target;

	public:
		AForm();
		AForm( std::string name, int gradeToSign, int gradeToExecute , std::string target);
		AForm( const AForm& copy );
		virtual ~AForm();

		AForm& operator=( const AForm& other );

		std::string	getName() const;
		bool		getIsSigned() const;
		int 		getGradeToSign() const;
		int			getGradeToExecute() const;
		std::string	getTarget() const;

		void	beSigned( Bureaucrat& bureaucrat );

		void			execute( Bureaucrat const& executor ) const;
		virtual void	action() const = 0;

		class GradeTooHighException : public std::exception
		{
			const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& AForm);

#endif
