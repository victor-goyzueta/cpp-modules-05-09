#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"

#include <iostream>
#include <string>
#include <fstream>

#define signReq	145
#define execReq	137
#define SCF	"ShrubberyCreationForm"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("default", signReq, execReq, "default") {}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string& target )
	: AForm( SCF, signReq, execReq, target ) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& copy )
	: AForm( SCF, signReq, execReq, copy.getTarget() ) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::action() const
{
	std::string		fileName = (getTarget() + "_shrubbery").c_str();
	std::ofstream	file(fileName.c_str());

	if (!file)
	{	
		std::cerr << "Error: Could not create shrubbery file." << std::endl;
		return;
	}

	file << " ######"			<< std::endl;
	file << "#0##0#0#  ####"	<< std::endl;
	file << "###\\/### ######"	<< std::endl;
	file << "   || %   \\|/"	<< std::endl;
	file << "   || |    |   "	<< std::endl;
	file << "MMMMMMMMMMMMMMM"	<< std::endl;

	file.close();
}
