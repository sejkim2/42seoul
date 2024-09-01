#include "Bureaucrat.hpp"

int main(void)
{
    {
        try
        {
            Bureaucrat b1;
            std::cout << b1;
        }
        catch (Bureaucrat::GradeTooLowException &e)
        {
            std::cout << e.what();
        }
        catch (Bureaucrat::GradeTooHighException &e)
        {
            std::cout << e.what();
        }
        // finally
        std::cout << "\nfinish1\n";
    }

    {
        try {
            Bureaucrat b1("name1", 1);
            b1.increaseGrade();
        } catch(std::exception& e) {
            std::cout << e.what();
        }
        std::cout << "\nfinish2\n";
    }
}