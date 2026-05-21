#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#define signReq	72
#define execReq	45
#define RQF	"RobotomyRequestForm"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("default", signReq, execReq, "default") {}

RobotomyRequestForm::RobotomyRequestForm( const std::string& target )
	: AForm( RQF, signReq, execReq, target ) {}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& copy )
	: AForm( RQF, signReq, execReq, copy.getTarget() ) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::action() const
{
	std::cout << "BZZZZZZzzzzzz... drilling noises..." << std::endl;

	if (std::rand() % 2 == 0)
		std::cout	<< this->getTarget()
					<< " has been robotomized successfully!" << std::endl;
	else
		std::cout	<< "Robotomy failed on "
					<< this->getTarget() << "." << std::endl;
}
