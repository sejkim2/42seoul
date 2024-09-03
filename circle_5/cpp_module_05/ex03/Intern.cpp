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

AForm* Intern::makeNewRobotomyRequest(const std::string& target)
{
    return (new RobotomyRequestForm(target));
}

AForm* Intern::makeNewPresidentialPardon(const std::string& target)
{
    return (new PresidentialPardonForm(target));
}

AForm* Intern::makeNewShrubberyCreation(const std::string& target)
{
    return (new ShrubberyCreationForm(target));
}

const char* Intern::NotExistFormName::what() const throw()
{
    return "Form With The Specified Name Does Not Exist!";
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    std::string formType[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};

    AForm* (Intern::*arr[3])(const std::string&) = {
        &Intern::makeNewPresidentialPardon,
        &Intern::makeNewRobotomyRequest,
        &Intern::makeNewShrubberyCreation
    };

    for(int i = 0; i < 3; i++)
    {
        if (formType[i].compare(formName) == 0)
            return (*this.*arr[i])(target);
    }
    throw (Intern::NotExistFormName());
}