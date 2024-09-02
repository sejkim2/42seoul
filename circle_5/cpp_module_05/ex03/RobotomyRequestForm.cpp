#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
: AForm("default robotomyRequestForm", 72, 45), target("Nontarget")
{
    std::srand(std::time(0));
    // std::cout << "RobotomyRequestForm Default Constructor Called" << '\n';
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    // std::cout << "RobotomyRequestForm Default Destructor Called" << '\n';
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& robotomyRequestForm)
{
    *this = robotomyRequestForm;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& robotomyRequestForm)
{
    if (&robotomyRequestForm != this)
    {
    }
    return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm(target + "Form", 72, 45), target(target)
{
    std::srand(std::time(0));
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    AForm::checkExecutable(executor);
    
    if (std::rand() % 2 == 0)
        std::cout << this->getTarget() << " has been robotomized successful";
    else
        std::cout << this->getTarget() << " has been robotomized fail";
    std::cout << '\n';
}

const std::string& RobotomyRequestForm::getTarget(void) const
{
    return (this->target);
}

std::ostream& operator<<(std::ostream& out, const RobotomyRequestForm& robotomyRequestForm)
{
    out << static_cast<const AForm&>(robotomyRequestForm);
    out << "target: " << robotomyRequestForm.getTarget() << '\n';
    return (out);
}
