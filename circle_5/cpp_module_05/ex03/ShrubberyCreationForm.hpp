#ifndef _SHRUBBERY_CREATION_FORM_HPP__
# define _SHRUBBERY_CREATION_FORM_HPP__

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm: public AForm
{
    public:
        ShrubberyCreationForm(void);
        virtual ~ShrubberyCreationForm(void);

        ShrubberyCreationForm(std::string target);
        virtual void execute(Bureaucrat const & executor) const;

        const std::string& getTarget(void) const;

    private:
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& shrubberyCreationForm);
        ShrubberyCreationForm(const ShrubberyCreationForm& shrubberyCreationForm);
        std::string target;
};

std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& shrubberyCreationForm);

#endif