#include "RPN.hpp"

Rpn::Rpn(void)
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
    std::stack<int> stack;
    std::stringstream ss(this->expression);
    std::string readStr;

    while (ss >> readStr)
    {
        if (readStr.length() != 1)
            throw std::runtime_error("Error");
        
        if (std::isdigit(readStr[0]))
            stack.push(std::stoi(readStr));
        else
        {
            if (!(readStr == "+" || readStr == "-" || readStr == "*" || readStr == "/"))
                throw std::runtime_error("Error");
            
            int op1 = stack.top();
            stack.pop();
            int op2 = stack.top();
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
                    throw std::runtime_error("Error");
                else
                    stack.push(op2 / op1);
            }
            else
                throw std::runtime_error("Error");
        }
    }
    if (stack.size() != 1)
        throw std::runtime_error("Error");
    std::cout << stack.top();
}