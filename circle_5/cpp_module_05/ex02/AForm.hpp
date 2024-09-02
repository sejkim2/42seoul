#ifndef _AFORM_HPP__
# define _AFORM_HPP__

# include <iostream>
# define LOWEST_GRADE 150
# define HIGHEST_GRADE 1

class Bureaucrat;

class AForm
{
    public:
        AForm(void);
        virtual ~AForm(void);
        AForm(const AForm& aForm);
        AForm& operator=(const AForm& aForm);

        AForm(std::string name, int requiredSignGrade, int requiredExecuteGrade);

        std::string getName() const;
        bool getIsSigned() const;
        int getRequiredSignGrade() const;
        int getRequiredExecuteGrade() const;

        void beSigned(const Bureaucrat& bureaucrat);

        void execute(Bureaucrat const & executor) const;
        virtual void executeAction(void) const = 0;
    
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

        class FormNotSignedException : public std::exception
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

std::ostream& operator<<(std::ostream& out, const AForm& aForm);

#endif