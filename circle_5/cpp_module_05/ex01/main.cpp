#include "Bureaucrat.hpp"

int main(void)
{
    try {
        Bureaucrat b1;
        std::cout << b1;
    } catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what();
    }
    catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << e.what();
    }
    //finally
    std::cout << "\nfinish";
}