#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try {
        std::cout << "=== Testing Bureaucrat and Abstract Form ===" << std::endl;
        Bureaucrat bob("Bob", 20);
        std::cout << bob << std::endl;
        
        std::cout << "\n=== Testing ShrubberyCreationForm ===" << std::endl;
        ShrubberyCreationForm shrubForm("garden");
        std::cout << shrubForm << std::endl;
        
        bob.signAForm(shrubForm);
        
        // Create a bureaucrat who can execute the shrubbery form
        Bureaucrat gardener("Gardener", 137);
        std::cout << gardener << std::endl;
        gardener.signAForm(shrubForm); // This should execute fine even though the form is already signed
        
        gardener.executeForm(shrubForm);
        
        std::cout << "\n=== Testing RobotomyRequestForm ===" << std::endl;
        RobotomyRequestForm robotForm("Bender");
        std::cout << robotForm << std::endl;
        
        Bureaucrat engineer("Engineer", 45);
        std::cout << engineer << std::endl;
        engineer.signAForm(robotForm);
        
        engineer.executeForm(robotForm);
        
        std::cout << "\n=== Testing PresidentialPardonForm ===" << std::endl;
        PresidentialPardonForm pardonForm("Criminal");
        std::cout << pardonForm << std::endl;
        
        Bureaucrat president("President", 5);
        std::cout << president << std::endl;
        president.signAForm(pardonForm);
        
        president.executeForm(pardonForm);
        
        // Test execution failure due to insufficient grade
        std::cout << "\n=== Testing execution failure ===" << std::endl;
        Bureaucrat lowRank("LowRank", 140);
        std::cout << lowRank << std::endl;
        
        lowRank.executeForm(shrubForm); // Should not execute
        
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}