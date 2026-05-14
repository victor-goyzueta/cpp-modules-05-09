#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"

#include <iostream>
#include <string>

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat( std::string name, int grade )
	: _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat( const Bureaucrat& copy ) : _name(copy._name)
{
	this->_grade = copy._grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& other )
{
	if (this != &other)
		this->_grade = other._grade;
	return (*this);
}

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

void	Bureaucrat::signForm( AForm &AForm )
{
	try
	{
		AForm.beSigned(*this);
		std::cout << this->_name << " signed " << AForm.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " couldn't sign " << AForm.getName()
				  << " because " << e.what() << std::endl;
	}
}

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
