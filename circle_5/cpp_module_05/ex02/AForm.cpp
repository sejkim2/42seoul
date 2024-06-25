#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void)
: name("default aForm"), isSigned(false), signGrade(LOWEST_GRADE), executeGrade(LOWEST_GRADE)
{
    std::cout << "AForm Default Constructor Called" << '\n';
}

AForm::~AForm(void)
{
    std::cout << "AForm Default Destructor Called" << '\n';
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
        this->signGrade = aForm.getSignGrade();
        this->executeGrade = aForm.getExecuteGrade();
    }
    return (*this);
}

AForm::AForm(std::string name, int signGrade, int executeGrade)
{
    if (signGrade > LOWEST_GRADE)
        throw AForm::GradeTooLowException();
    else if (signGrade < HIGHEST_GRADE)
        throw AForm::GradeTooHighException();
    
    if (executeGrade > LOWEST_GRADE)
        throw AForm::GradeTooLowException();
    else if (executeGrade < HIGHEST_GRADE)
        throw AForm::GradeTooHighException();
    
    this->name = name;
    this->signGrade = signGrade;
    this->executeGrade = executeGrade;
}

std::string AForm::getName() const
{
    return (this->name);
}

bool AForm::getIsSigned() const
{
    return (this->isSigned);
}

int AForm::getSignGrade() const
{
    return (this->signGrade);
}

int AForm::getExecuteGrade() const
{
    return (this->executeGrade);
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= this->getSignGrade())
        this->isSigned = true;
    else
        throw AForm::GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (this->getIsSigned() == false)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() < this->getSignGrade())
        throw Bureaucrat::GradeTooLowException();
    
    executeAction();
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade Too High";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade Too Low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form Not Signed";
}

std::ostream& operator<<(std::ostream& out, const AForm& aForm)
{
    std::string isSigned = aForm.getIsSigned() ? "signed" : "no signed";
    
    out << aForm.getName() << "," << "isSigned :  " << isSigned;
    out << " ,signGrade : " << aForm.getSignGrade();
    out << " ,executeGrade : " << aForm.getExecuteGrade() << '\n';
    return (out);
}
