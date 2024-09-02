#ifndef _FORM_HPP__
# define _FORM_HPP__

# include <iostream>
# define LOWEST_GRADE 150
# define HIGHEST_GRADE 1

class Bureaucrat;

class Form
{
    public:
        Form(void);
        ~Form(void);

        Form(const std::string& name, int requiredSignGrade, int requiredExecuteGrade);

        const std::string& getName() const;
        bool getIsSigned() const;
        int getRequiredSignGrade() const;
        int getRequiredExecuteGrade() const;

        void beSigned(const Bureaucrat& bureaucrat);

        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };

    private:
        Form(const Form& form);
        Form& operator=(const Form& form);
        const std::string name;
        bool isSigned;
        const int requiredSignGrade;
        const int requiredExecuteGrade;
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif