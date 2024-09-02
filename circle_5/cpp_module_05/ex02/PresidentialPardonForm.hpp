#ifndef _PRESIDENTIAL_PARDON_FORM_HPP__
# define _PRESIDENTIAL_PARDON_FORM_HPP__

# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
    public:
        PresidentialPardonForm(void);
        virtual ~PresidentialPardonForm(void);
        PresidentialPardonForm(const PresidentialPardonForm& presidentialPardonForm);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& presidentialPardonForm);

        PresidentialPardonForm(std::string target);
        virtual void executeAction(void) const;

        std::string getTarget(void) const;
    private:
        std::string target;
};

std::ostream& operator<<(std::ostream& out, const PresidentialPardonForm& presidentialPardonForm);

#endif