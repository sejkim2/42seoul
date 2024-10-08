#ifndef _INTERN_HPP__
# define _INTERN_HPP__

# include <iostream>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Bureaucrat;

class Intern
{
    public:
        Intern(void);
        virtual ~Intern(void);
        Intern(const Intern& aForm);
        Intern& operator=(const Intern& aForm);

        AForm* makeForm(const std::string& formName, const std::string& target);

        class NotExistFormName : public std::exception
        {
            public:
                const char* what() const throw();
        };
    
    private:
        AForm* makeNewPresidentialPardon(const std::string& target);
        AForm* makeNewRobotomyRequest(const std::string& target);
        AForm* makeNewShrubberyCreation(const std::string& target);
};

std::ostream& operator<<(std::ostream& out, const AForm& aForm);

#endif