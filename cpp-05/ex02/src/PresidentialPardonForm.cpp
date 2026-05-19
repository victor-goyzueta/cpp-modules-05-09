#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"

#include <iostream>
#include <string>
#include <fstream>

#define signReq	25
#define execReq	5
#define RQF	"PresidentialPardonForm"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("default", signReq, execReq, "default") {}

PresidentialPardonForm::PresidentialPardonForm( const std::string& target )
	: AForm( RQF, signReq, execReq, target ) {}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& copy )
	: AForm( RQF, signReq, execReq, copy.getTarget() ) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::action() const
{
	std::cout << this->getTarget()
			  << " has been pardoned by Zaphod Beeblebrox."	<< std::endl;
}
