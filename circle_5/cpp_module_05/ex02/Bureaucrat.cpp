#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(void)
: name("default name"), grade(LOWEST_GRADE)
{
    // std::cout << "Bureaucrat Default Constructor Called" << '\n';
}

Bureaucrat::~Bureaucrat(void)
{
    // std::cout << "Bureaucrat Default Destructor Called" << '\n';
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat)
{
    *this = bureaucrat;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bureaucrat)
{
    if (&bureaucrat != this)
    {
    }
    return (*this);
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
: name(name)
{
    if (grade > LOWEST_GRADE)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < HIGHEST_GRADE)
        throw Bureaucrat::GradeTooHighException();
    else
        this->grade = grade;
}

const std::string& Bureaucrat::getName(void) const
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

void Bureaucrat::signForm(AForm& aForm)
{
    try {
        aForm.beSigned(*this);
        std::cout << this->name << " signed " << aForm.getName();
    }
    catch (AForm::GradeTooLowException& e) {
        std::cout << this->name << " couldn't sign " << aForm.getName() << " because " << e.what();
    }
    std::cout << '\n';
}

void Bureaucrat::executeForm(AForm const & form) const
{
    try {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << '\n';
    } catch (AForm::FormNotSignedException &e) {
        std::cout << e.what();
    } catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << e.what();
    }
    std::cout << '\n';
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat Grade Too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat Grade Too Low";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
    out << bureaucrat.getName() << "," << "bureaucrat grade " << bureaucrat.getGrade() << '\n';
    return (out);
}
