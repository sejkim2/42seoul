#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
: AForm("default robotomyRequestForm", 72, 45), target("Nontarget")
{
    // std::cout << "RobotomyRequestForm Default Constructor Called" << '\n';
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    // std::cout << "RobotomyRequestForm Default Destructor Called" << '\n';
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& robotomyRequestForm)
: AForm(robotomyRequestForm)
{
    *this = robotomyRequestForm;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& robotomyRequestForm)
{
    if (&robotomyRequestForm != this)
    {
        AForm::operator=(robotomyRequestForm);
        this->target = robotomyRequestForm.getTarget();
    }
    return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm(target + "Form", 72, 45), target(target)
{
}

void RobotomyRequestForm::executeAction(void) const
{
    std::srand(std::time(0));

    if (std::rand() % 2 == 0)
        std::cout << this->getTarget() << " has been robotomized successful";
    else
        std::cout << this->getTarget() << " has been robotomized fail";
    std::cout << '\n';
}

std::string RobotomyRequestForm::getTarget(void) const
{
    return (this->target);
}

std::ostream& operator<<(std::ostream& out, const RobotomyRequestForm& robotomyRequestForm)
{
    out << static_cast<const AForm&>(robotomyRequestForm);
    out << "target: " << robotomyRequestForm.getTarget() << '\n';
    return (out);
}
