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

    try {
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        Bureaucrat b1("kim", 1);
    
        b1.signForm(*rrf);
        b1.executeForm(*rrf);
    } catch (std::exception& e) {
        std::cout << e.what();
    }
}