#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        std::cout << "argument error\n";
    else
    {
        Rpn rpn(argv[1]);
        try {
            rpn.calculation();
        } catch(std::exception& e) {
            std::cout << e.what();
        }
    }
}