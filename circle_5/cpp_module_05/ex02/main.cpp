#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

int main(void)
{
    ShrubberyCreationForm form1("home");
    RobotomyRequestForm form2("office");
    PresidentialPardonForm form3("white house");

    Bureaucrat b1("kim", 40);
    b1.signForm(form1);
    b1.signForm(form2);
    b1.signForm(form3);

    b1.executeForm(form1);
    b1.executeForm(form2);
    b1.executeForm(form3);
}