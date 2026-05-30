#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"

#include <iostream>
#include <string>
#include <fstream>

#define signReq	25
#define execReq	5
#define PPF	"PresidentialPardonForm"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("default", signReq, execReq, "default") {}

PresidentialPardonForm::PresidentialPardonForm( const std::string& target )
	: AForm( PPF, signReq, execReq, target ) {}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& copy )
	: AForm( PPF, signReq, execReq, copy.getTarget() ) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::action() const
{
	std::cout << this->getTarget()
			  << " has been pardoned by Zaphod Beeblebrox."	<< std::endl;
}
