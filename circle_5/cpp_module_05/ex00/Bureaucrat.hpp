#ifndef _BUREAUCRAT_HPP__
# define _BUREAUCRAT_HPP__

# include <iostream>

class Bureaucrat
{
    public:
        Bureaucrat(void);
        ~Bureaucrat(void);
        Bureaucrat(const Bureaucrat& bureaucrat);
        Bureaucrat& operator=(const Bureaucrat& bureaucrat);

        std::string getName(void) const;
        int getGrade(void) const;
        void increaseGrade(int amount);
        void decreaseGrade(int amount);

        
    private:
        std::string name;
        unsigned int grade;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& Bureaucrat);

#endif