#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    try {
        Bureaucrat b1;
        Form f1("f1", 124, 124);
        b1.signForm(f1);
    } catch (Form::GradeTooLowException& e) {
        std::cout << e.what();
    }
    catch (Form::GradeTooHighException& e) {
        std::cout << e.what();
    }
    //finally
    std::cout << "\nfinish";
}