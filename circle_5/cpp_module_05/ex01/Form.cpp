#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void)
: name("default form"), isSigned(false), signGrade(LOWEST_GRADE), executeGrade(LOWEST_GRADE)
{
    // std::cout << "Form Default Constructor Called" << '\n';
}

Form::~Form(void)
{
    // std::cout << "Form Default Destructor Called" << '\n';
}

Form::Form(const Form& form)
{
    *this = form;
}

Form& Form::operator=(const Form& form)
{
    if (&form != this)
    {
        this->name = form.getName();
        this->isSigned = form.getIsSigned();
        this->signGrade = form.getSignGrade();
        this->executeGrade = form.getExecuteGrade();
    }
    return (*this);
}

Form::Form(std::string name, int signGrade, int executeGrade)
{
    if (signGrade > LOWEST_GRADE)
        throw Form::GradeTooLowException();
    else if (signGrade < HIGHEST_GRADE)
        throw Form::GradeTooHighException();
    
    if (executeGrade > LOWEST_GRADE)
        throw Form::GradeTooLowException();
    else if (executeGrade < HIGHEST_GRADE)
        throw Form::GradeTooHighException();
    
    this->name = name;
    this->signGrade = signGrade;
    this->executeGrade = executeGrade;
}


std::string Form::getName() const
{
    return (this->name);
}

bool Form::getIsSigned() const
{
    return (this->isSigned);
}

int Form::getSignGrade() const
{
    return (this->signGrade);
}

int Form::getExecuteGrade() const
{
    return (this->executeGrade);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= this->getSignGrade())
        this->isSigned = true;
    else
        throw Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade Too High";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade Too Low";
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
    std::string isSigned = form.getIsSigned() ? "signed" : "no signed";
    
    out << form.getName() << "," << "isSigned :  " << isSigned;
    out << " ,signGrade : " << form.getSignGrade();
    out << " ,executeGrade : " << form.getExecuteGrade() << '\n';
    return (out);
}