#ifndef _BUREAUCRAT_HPP__
# define _BUREAUCRAT_HPP__

# include <iostream>
# define LOWEST_GRADE 150
# define HIGHEST_GRADE 1

class Form;

class Bureaucrat
{
    public:
        Bureaucrat(void);
        ~Bureaucrat(void);
        Bureaucrat(const Bureaucrat& bureaucrat);
        Bureaucrat& operator=(const Bureaucrat& bureaucrat);

        Bureaucrat(std::string name, int grade);
        std::string getName(void) const;
        int getGrade(void) const;
        void increaseGrade();
        void decreaseGrade();

        void signForm(Form& form);

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
        int grade;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif