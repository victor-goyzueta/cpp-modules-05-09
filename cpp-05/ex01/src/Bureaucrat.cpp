#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

#include <iostream>
#include <string>

Bureaucrat::Bureaucrat( std::string name, int grade )
	: _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

void	Bureaucrat::signForm(Form &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->_name << " signed " << f.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " couldn't sign " << f.getName()
				  << " because " << e.what();
	}
}

// void Bureaucrat::signForm( Form& form )
// {
// 	form.beSigned( *this );
// 	if (form.getIsSigned())
// 		std::cout << this->getName() << " signed " << form.getName() << std::endl;
// 	else
// 		std::cout
// 			<< this->getName()
// 			<< " couldn't sign "
// 			<< form.getName()
// 			<< " because it grade isn't enough" << std::endl;
// }

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat grade to high!");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat grade to low!");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os	<< bureaucrat.getName()
		<< ", bureaucrat grade "
		<< bureaucrat.getGrade() << ".";
	return (os);
}
