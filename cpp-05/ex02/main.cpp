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
    std::srand(std::time(NULL));

    try
    {
        Bureaucrat alice("Alice", 1);
        Bureaucrat bob("Bob", 140);
        Bureaucrat carl("Carl", 150);

        AForm *shrub = new ShrubberyCreationForm("garden");
        AForm *robo = new RobotomyRequestForm("Bender");
        AForm *pres = new PresidentialPardonForm("Ford");

        // ---- CASO 1: Intento de ejecutar sin firmar ----
        try
        {
            shrub->execute(alice); // debería fallar
        }
        catch (const std::exception &e)
        {
            std::cerr << "[Test 1] " << e.what() << std::endl;
        }

        // ---- CASO 2: Carl intenta firmar (debería fallar) ----
        try
        {
            carl.signForm(*shrub);
        }
        catch (const std::exception &e)
        {
            std::cerr << "[Test 2] " << e.what() << std::endl;
        }

        // ---- CASO 3: Bob firma Shrubbery (éxito), pero no puede ejecutarlo ----
        try
        {
            bob.signForm(*shrub);
            bob.executeForm(*shrub); // debe fallar por permisos
        }
        catch (const std::exception &e)
        {
            std::cerr << "[Test 3] " << e.what() << std::endl;
        }

        // ---- CASO 4: Alice firma y ejecuta los 3 formularios ----
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
            std::cerr << "[Test 4] " << e.what() << std::endl;
        }

        // ---- CASO 5: Alice también ejecuta Shrubbery que firmó Bob ----
        try
        {
            alice.executeForm(*shrub); // debe tener éxito
        }
        catch (const std::exception &e)
        {
            std::cerr << "[Test 5] " << e.what() << std::endl;
        }
        delete shrub;
        delete robo;
        delete pres;
    }
    catch (const std::exception &e)
    {
        std::cerr << "[FATAL ERROR] " << e.what() << std::endl;
    }
}