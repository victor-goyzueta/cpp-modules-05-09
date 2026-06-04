#include "inc/Bureaucrat.hpp"
#include "inc/AForm.hpp"
#include "inc/PresidentialPardonForm.hpp"
#include "inc/ShrubberyCreationForm.hpp"
#include "inc/RobotomyRequestForm.hpp"

#include <iostream>
#include <string>
#include <cstdlib>

int main()
{
    std::srand(time(NULL));

    try
    {
        Bureaucrat alice("Alice", 1);
        Bureaucrat bob("Bob", 140);
        Bureaucrat carl("Carl", 150);

        AForm *shrub = new ShrubberyCreationForm("Garden");
        AForm *robo = new RobotomyRequestForm("Bender");
        AForm *pres = new PresidentialPardonForm("Ford");

        try
        {
            shrub->execute(alice);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }

        try
        {
            carl.signForm(*shrub);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }

        try
        {
            bob.signForm(*shrub);
            bob.executeForm(*shrub);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }

        try
        {
            alice.signForm(*robo);
            alice.signForm(*pres);
			alice.signForm(*shrub);
            alice.executeForm(*robo);
            alice.executeForm(*pres);
			alice.executeForm(*shrub);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }

        delete shrub;
        delete robo;
        delete pres;
    }
    catch (const std::exception &e)
    {
        std::cerr << "[Error]" << e.what() << std::endl;
    }
}
