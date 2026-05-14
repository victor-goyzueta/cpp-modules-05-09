#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"

#include <iostream>
#include <string>

AForm::AForm()
	: _name("deafult"), _gradeToSign(1), _gradeToExecute(1), _target("default") {}

AForm::AForm( std::string name, int gradeToSign, int gradeToExecute, std::string target )
	:	_name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _target(target)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw (GradeTooHighException());
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw (GradeTooLowException());
	_isSigned = false;
}

AForm::AForm( const AForm& copy )
	:	_name(copy._name), _gradeToSign(copy._gradeToSign),
		_gradeToExecute(copy._gradeToExecute), _target(copy._target)
{
	_isSigned = copy._isSigned;
}

AForm::~AForm() {}

AForm& AForm::operator=( const AForm& other )
{
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

std::string AForm::getName() const
{
	return (_name);
}

bool AForm::getIsSigned() const
{
	return (_isSigned);
}

int AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

std::string AForm::getTarget() const
{
	return (_target);
}

void AForm::beSigned( Bureaucrat& bureaucrat )
{
	if (bureaucrat.getGrade() > this->getGradeToSign())
		throw (GradeTooLowException());
	_isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("AForm grade too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("AForm grade too low!");
}

std::ostream& operator<<(std::ostream& os, const AForm& AForm)
{
	std::string	status;

	if (AForm.getIsSigned())
		status = "is signed.";
	else
		status = "is not signed.";

	os << AForm.getName() << ", AForm to sign grade " << AForm.getGradeToSign()
	   << ", AForm grade to Execute " << AForm.getGradeToExecute()
	   << ", AForm " << status << std::endl;
	return (os);
}
