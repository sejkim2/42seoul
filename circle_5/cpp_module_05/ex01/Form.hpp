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
        Form(const Form& form);
        Form& operator=(const Form& form);

        Form(std::string name, int requiredSignGrade, int requiredExecuteGrade);

        std::string getName() const;
        bool getIsSigned() const;
        int getReauiredSignGrade() const;
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
        std::string name;
        bool isSigned;
        int requiredSignGrade;
        int requiredExecuteGrade;
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif