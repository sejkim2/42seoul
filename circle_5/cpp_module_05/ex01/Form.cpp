#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void)
: name("default form"), isSigned(false), requiredSignGrade(LOWEST_GRADE), requiredExecuteGrade(LOWEST_GRADE)
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
        this->requiredSignGrade = form.getReauiredSignGrade();
        this->requiredExecuteGrade = form.getRequiredExecuteGrade();
    }
    return (*this);
}

Form::Form(std::string name, int requiredSignGrade, int requiredExecuteGrade)
{
    if (requiredSignGrade > LOWEST_GRADE)
        throw Form::GradeTooLowException();
    else if (requiredSignGrade < HIGHEST_GRADE)
        throw Form::GradeTooHighException();
    
    if (requiredExecuteGrade > LOWEST_GRADE)
        throw Form::GradeTooLowException();
    else if (requiredExecuteGrade < HIGHEST_GRADE)
        throw Form::GradeTooHighException();
    
    this->name = name;
    this->requiredSignGrade = requiredSignGrade;
    this->requiredExecuteGrade = requiredExecuteGrade;
}


std::string Form::getName() const
{
    return (this->name);
}

bool Form::getIsSigned() const
{
    return (this->isSigned);
}

int Form::getReauiredSignGrade() const
{
    return (this->requiredSignGrade);
}

int Form::getRequiredExecuteGrade() const
{
    return (this->requiredExecuteGrade);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= this->getReauiredSignGrade())
        this->isSigned = true;
    else
        throw Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form Grade Too High";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form Grade Too Low";
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
    std::string isSigned = form.getIsSigned() ? "signed" : "no signed";
    
    out << form.getName() << "," << "isSigned :  " << isSigned;
    out << " ,requiredSignGrade : " << form.getReauiredSignGrade();
    out << " ,requiredExecuteGrade : " << form.getRequiredExecuteGrade() << '\n';
    return (out);
}