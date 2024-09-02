#ifndef _PRESIDENTIAL_PARDON_FORM_HPP__
# define _PRESIDENTIAL_PARDON_FORM_HPP__

# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
    public:
        PresidentialPardonForm(void);
        virtual ~PresidentialPardonForm(void);

        PresidentialPardonForm(std::string target);
        void execute(Bureaucrat const & executor) const;

        const std::string& getTarget(void) const;

    private:
        PresidentialPardonForm(const PresidentialPardonForm& presidentialPardonForm);
        std::string target;
        PresidentialPardonForm& operator=(const PresidentialPardonForm& presidentialPardonForm);
};

std::ostream& operator<<(std::ostream& out, const PresidentialPardonForm& presidentialPardonForm);

#endif