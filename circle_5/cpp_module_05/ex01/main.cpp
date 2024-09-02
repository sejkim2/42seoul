#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    {
        std::cout << "_____________________test 1_____________________" << '\n';
        try
        {
            Bureaucrat b1("b1", 123);
            Form f1("f1", 124, 124);
            b1.signForm(f1);
        }
        catch (std::exception &e)
        {
            std::cout << e.what();
        }
    }

    {
        std::cout << "_____________________test 2_____________________" << '\n';
        try {
            Bureaucrat b1;
            Form f1("f1", 124, 124);
            b1.signForm(f1);
        } catch(std::exception& e) {
            std::cout << e.what();
        }
    }
}