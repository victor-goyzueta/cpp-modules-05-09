#include "inc/Bureaucrat.hpp"
#include "inc/Form.hpp"

#include <iostream>
#include <string>

int main()
{
    try 
	{
        Bureaucrat bob("Bob", 50);
        Form taxForm("TaxForm", 100, 100);

        std::cout << taxForm << std::endl;
        bob.signForm(taxForm);
        std::cout << taxForm << std::endl;

        Bureaucrat karen("Karen", 120);
        Form secretForm("SecretForm", 100, 100);

        std::cout << secretForm << std::endl;
        karen.signForm(secretForm);
        std::cout << secretForm << std::endl;

    }
	catch (std::exception &e) 
	{
        std::cerr << "Caught error in main: " << e.what() << std::endl;
    }
    return (0);
}
