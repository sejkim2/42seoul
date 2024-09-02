#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
: AForm("default presidentialPardonForm", 25, 5), target("Nontarget")
{
    // std::cout << "presidentialPardonForm Default Constructor Called" << '\n';
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    // std::cout << "presidentialPardonForm Default Destructor Called" << '\n';
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& presidentialPardonForm)
: AForm(presidentialPardonForm)
{
    *this = presidentialPardonForm;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& presidentialPardonForm)
{
    if (&presidentialPardonForm != this)
    {
        AForm::operator=(presidentialPardonForm);
        this->target = presidentialPardonForm.getTarget();
    }
    return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm(target + "Form", 25, 5), target(target)
{
}

void PresidentialPardonForm::executeAction(void) const
{
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << '\n';
}

std::string PresidentialPardonForm::getTarget(void) const
{
    return (this->target);
}

std::ostream& operator<<(std::ostream& out, const PresidentialPardonForm& presidentialPardonForm)
{
    out << static_cast<const AForm&>(presidentialPardonForm);
    out << "target: " << presidentialPardonForm.getTarget() << '\n';
    return (out);
}
