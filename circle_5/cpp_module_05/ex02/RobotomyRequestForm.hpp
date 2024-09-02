#ifndef _ROBOTOMY_REQUEST_FORM_HPP__
# define _ROBOTOMY_REQUEST_FORM_HPP__

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm: public AForm
{
    public:
        RobotomyRequestForm(void);
        virtual ~RobotomyRequestForm(void);

        RobotomyRequestForm(std::string target);
        virtual void execute(Bureaucrat const & executor) const;

        const std::string& getTarget(void) const;
    private:
        RobotomyRequestForm(const RobotomyRequestForm& robotomyRequestForm);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& robotomyRequestForm);
        std::string target;
};

std::ostream& operator<<(std::ostream& out, const RobotomyRequestForm& robotomyRequestForm);

#endif