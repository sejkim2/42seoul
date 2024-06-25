#ifndef _SHRUBBERY_CREATION_FORM_HPP__
# define _SHRUBBERY_CREATION_FORM_HPP__

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm: public AForm
{
    public:
        ShrubberyCreationForm(void);
        virtual ~ShrubberyCreationForm(void);
        ShrubberyCreationForm(const ShrubberyCreationForm& shrubberyCreationForm);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& shrubberyCreationForm);

        ShrubberyCreationForm(std::string target);
        virtual void executeAction(void) const = 0;

        std::string getTarget(void) const;
    private:
        std::string target;
};

std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& shrubberyCreationForm);

#endif