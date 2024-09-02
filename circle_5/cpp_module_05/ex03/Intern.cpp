#include "Intern.hpp"

Intern::Intern(void)
{
    // std::cout << "this is Intern constructor" << '\n';
}

Intern::~Intern(void)
{
    // std::cout << "this is Intern destructor" << '\n';
}
        
Intern::Intern(const Intern& intern)
{
    *this = intern;
}

Intern& Intern::operator=(const Intern& intern)
{
    if (&intern == this)
        return (*this);    
    return (*this);
}

AForm* makeForm(const std::string& formName, const std::string& target)
{
    std::string formType[3] = {"robotomy request", "presidential pardon", "shrubbery creation"}
}
