#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main(void)
{
    Intern someRandomIntern;
    AForm* rrf;

    std::cout << "_________________________________________________________________" << '\n';
    std::cout << "1. make robotomy : [robotomy request]" << '\n';
    std::cout << "2. make presidential : [presidential pardon]" << '\n';
    std::cout << "3. make shrubbery : [shrubbery creation]" << '\n';
    std::cout << "other : Throw NotExistFormName Exception" << '\n';
    std::cout << "_________________________________________________________________" << '\n';
    
    try { 
        // rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        // rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
        rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
        Bureaucrat b1("kim", 1);
    
        b1.signForm(*rrf);
        b1.executeForm(*rrf);
    } catch (std::exception& e) {
        std::cout << e.what();
    }
}