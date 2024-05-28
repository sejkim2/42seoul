#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade)
 : name(name), grade(grade)
{
    int thisGrade = this->getGrade();

    if (thisGrade > MAX_GRADE)
        throw Bureaucrat::GradeTooLowException();
    if (thisGrade < MIN_GRADE)
        throw Bureaucrat::GradeTooHighException();
}

std::string Bureaucrat::getName(void) const
{
    return (this->name);
}

int Bureaucrat::getGrade(void) const
{
    return (this->grade);
}

void Bureaucrat::increaseGrade()
{
    this->grade--;
}

void Bureaucrat::decreaseGrade()
{
    this->grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade Too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade Too Low";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
    out << bureaucrat.getName() << "," << "bureaucrat grade " << bureaucrat.getGrade() << '\n';
    return (out);
}
