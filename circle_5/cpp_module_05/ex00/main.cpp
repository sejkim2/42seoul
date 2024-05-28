#include "Bureaucrat.hpp"

int main(void)
{
    try {
        // Bureaucrat b1("b1", 151);
        Bureaucrat b2("b2", -1);
    } catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what();
    }
    catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << e.what();
    }
    //finally
    std::cout << "\nfinish";
}