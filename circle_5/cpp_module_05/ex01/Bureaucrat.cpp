#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void)
: name("default name"), grade(LOWEST_GRADE)
{
    std::cout << "Bureaucrat Default Constructor Called" << '\n';
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat Default Destructor Called" << '\n';
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat)
{
    *this = bureaucrat;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bureaucrat)
{
    if (&bureaucrat != this)
    {
        this->name = bureaucrat.getName();
        this->grade = bureaucrat.getGrade();
    }
    return (*this);
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
    if (grade > LOWEST_GRADE)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < HIGHEST_GRADE)
        throw Bureaucrat::GradeTooHighException();
    else
        this->grade = grade;

    this->name = name;
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
    if (this->getGrade() == HIGHEST_GRADE)
        throw Bureaucrat::GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decreaseGrade()
{
    if (this->getGrade() == LOWEST_GRADE)
        throw Bureaucrat::GradeTooLowException();
    this->grade++;
}

void Bureaucrat::signForm(Form& form)
{
    try {
        form.beSigned(*this);
        std::cout << this->name << " signed " << form.getName();
    }
    catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << this->name << " couldn't sign " << form.getName() << " because " << e.what();
    }
    //finally
    std::cout << '\n';
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
