#include "RPN.hpp"

Rpn::Rpn(void)
: expression("default")
{
    // std::cout << "Rpn Default Constructor Called" << '\n';
}

Rpn::~Rpn(void)
{
    // std::cout << "Rpn Default Destructor Called" << '\n';
}

Rpn::Rpn(const Rpn& copy)
{
    *this = copy;
}

Rpn& Rpn::operator=(const Rpn& obj)
{
    if (&obj != this)
    {
    }
    return (*this);
}

Rpn::Rpn(std::string str)
: expression(str)
{
}

void Rpn::calculation(void)
{
    std::stack<long> stack;
    std::stringstream ss(this->expression);
    std::string readStr;

    while (ss >> readStr)
    {
        if (readStr.length() != 1)
            throw std::runtime_error("Error\n");
        
        if (std::isdigit(readStr[0]))
        {
            std::istringstream iss(readStr);
            int number;
            iss >> number;
            stack.push(number);
        }
        else
        {
            if (!(readStr == "+" || readStr == "-" || readStr == "*" || readStr == "/"))
                throw std::runtime_error("Error\n");
            
            if (stack.size() < 2)
                throw std::runtime_error("Error\n");

            long op1 = stack.top();
            stack.pop();
            long op2 = stack.top();
            stack.pop();

            if (readStr == "+")
                stack.push(op2 + op1);
            else if (readStr == "-")
                stack.push(op2 - op1);
            else if (readStr == "*")
                stack.push(op2 * op1);
            else if (readStr == "/")
            {
                if (op1 == 0)
                    throw std::runtime_error("Error\n");
                else
                    stack.push(op2 / op1);
            }
            else
                throw std::runtime_error("Error\n");

            if (stack.top() > Rpn::MAX_INT || stack.top() < Rpn::MIN_INT)
                throw std::overflow_error("Error\n");
        }
    }
    if (stack.size() != 1)
        throw std::runtime_error("Error\n");
    std::cout << stack.top();
}