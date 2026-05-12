#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

#include <iostream>
#include <string>

Form::Form() : _name("default"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1) {}

Form::Form( std::string name, int gradeToSign, int gradeToExecute )
	:	_name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw (GradeTooHighException());
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw (GradeTooLowException());
	_isSigned = false;
}

Form::Form( const Form& copy )
	: _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	_isSigned = copy._isSigned;
}

Form::~Form() {}

Form& Form::operator=( const Form& other )
{
	if (this != &other)
		this->_isSigned = other._isSigned;
	return (*this);
}

std::string Form::getName() const
{
	return (_name);
}

bool Form::getIsSigned() const
{
	return (_isSigned);
}

int Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void Form::beSigned( Bureaucrat& bureaucrat )
{
	if (bureaucrat.getGrade() > this->getGradeToSign())
		throw (GradeTooLowException());
	_isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form grade too high!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form grade too low!");
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	std::string	status;

	if (form.getIsSigned())
		status = "is signed.";
	else
		status = "is not signed.";

	os << form.getName() << ", form to sign grade " << form.getGradeToSign()
	   << ", form grade to Execute " << form.getGradeToExecute()
	   << ", form " << status << std::endl;
	return (os);
}
