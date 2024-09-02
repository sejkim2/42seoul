#include "Bureaucrat.hpp"

int main(void)
{
    {
        std::cout << "_____________________test 1_____________________" << '\n';
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
        std::cout << "_____________________test 2_____________________" << '\n';
        try {
            Bureaucrat b1("name2", 1);
            b1.increaseGrade();
        } catch(std::exception& e) {
            std::cout << e.what();
        }
        std::cout << "\nfinish2\n";
    }

    {
        std::cout << "_____________________test 3_____________________" << '\n';
        try {
            Bureaucrat b1("name3", 1);
            std::cout << b1;
        } catch(std::exception& e) {
            std::cout << e.what();
        }
        std::cout << "\nfinish3\n";
    }
}