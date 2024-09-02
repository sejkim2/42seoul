#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    try {
        Bureaucrat b1("b1", 123);
        Form f1("f1", 124, 124);
        b1.signForm(f1);
    } catch (std::exception& e) {
        std::cout << e.what();
    }
}