#include "inc/AForm.hpp"
#include "inc/Bureaucrat.hpp"
#include "inc/ShrubberyCreationForm.hpp"
#include "inc/RobotomyRequestForm.hpp"
#include "inc/PresidentialPardonForm.hpp"
#include "inc/Intern.hpp"

#include <iostream>
#include <fstream>
#include <cstdlib>

int main() {
    srand(time(0));

    try {
        Bureaucrat miguel("Miguel", 1);
        Intern ryan;

        AForm* form = ryan.makeForm("ShrubberyCreationForm", "Ines");

        miguel.signForm(*form);
        miguel.executeForm(*form);
        delete form;
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        Bureaucrat miguel("Miguel", 1);
        Intern ryan;

        AForm* form = ryan.makeForm("RobotomyRequestForm", "Ines");

        miguel.signForm(*form);
        miguel.executeForm(*form);
        delete form;
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        Bureaucrat miguel("Miguel", 1);
        Intern ryan;

        AForm* form = ryan.makeForm( "PresidentialPardonForm", "Ines");

        miguel.signForm(*form);
        miguel.executeForm(*form);
        delete form;
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        Bureaucrat miguel("Miguel", 1);
        Intern ryan;

        AForm* form = ryan.makeForm( "asfds", "wiwi");

        miguel.signForm(*form);
        miguel.executeForm(*form);
        delete form;
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

}
