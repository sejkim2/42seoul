#ifndef _BUREAUCRAT_HPP__
# define _BUREAUCRAT_HPP__

# include <iostream>
# define LOWEST_GRADE 150
# define HIGHEST_GRADE 1

class Bureaucrat
{
    public:
        Bureaucrat(void);
        ~Bureaucrat(void);

        Bureaucrat(const std::string& name, int grade);
        const std::string& getName(void) const;
        int getGrade(void) const;
        void increaseGrade();
        void decreaseGrade();

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
        Bureaucrat(const Bureaucrat& bureaucrat);
        Bureaucrat& operator=(const Bureaucrat& bureaucrat);
        const std::string name;
        int grade;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif