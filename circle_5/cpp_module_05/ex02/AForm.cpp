#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void)
: name("default aForm"), isSigned(false), requiredSignGrade(LOWEST_GRADE), requiredExecuteGrade(LOWEST_GRADE)
{
    // std::cout << "AForm Default Constructor Called" << '\n';
}

AForm::~AForm(void)
{
    // std::cout << "AForm Default Destructor Called" << '\n';
}

AForm::AForm(const AForm& aForm)
{
    *this = aForm;
}

AForm& AForm::operator=(const AForm& aForm)
{
    if (&aForm != this)
    {
        this->name = aForm.getName();
        this->isSigned = aForm.getIsSigned();
        this->requiredSignGrade = aForm.getRequiredSignGrade();
        this->requiredExecuteGrade = aForm.getRequiredExecuteGrade();
    }
    return (*this);
}

AForm::AForm(std::string name, int requiredSignGrade, int requiredExecuteGrade)
{
    if (requiredSignGrade > LOWEST_GRADE)
        throw AForm::GradeTooLowException();
    else if (requiredSignGrade < HIGHEST_GRADE)
        throw AForm::GradeTooHighException();
    
    if (requiredExecuteGrade > LOWEST_GRADE)
        throw AForm::GradeTooLowException();
    else if (requiredExecuteGrade < HIGHEST_GRADE)
        throw AForm::GradeTooHighException();
    
    this->name = name;
    this->requiredSignGrade = requiredSignGrade;
    this->requiredExecuteGrade = requiredExecuteGrade;
}

std::string AForm::getName() const
{
    return (this->name);
}

bool AForm::getIsSigned() const
{
    return (this->isSigned);
}

int AForm::getRequiredSignGrade() const
{
    return (this->requiredSignGrade);
}

int AForm::getRequiredExecuteGrade() const
{
    return (this->requiredExecuteGrade);
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= this->getRequiredSignGrade())
        this->isSigned = true;
    else
        throw AForm::GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (this->getIsSigned() == false)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getRequiredSignGrade())
        throw Bureaucrat::GradeTooLowException();
    
    executeAction();
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Form Grade Too High";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Form Grade Too Low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form Not Signed";
}

std::ostream& operator<<(std::ostream& out, const AForm& aForm)
{
    std::string isSigned = aForm.getIsSigned() ? "signed" : "no signed";
    
    out << aForm.getName() << "," << "isSigned :  " << isSigned;
    out << " ,requiredSignGrade : " << aForm.getRequiredSignGrade();
    out << " ,requiredExecuteGrade : " << aForm.getRequiredExecuteGrade() << '\n';
    return (out);
}
