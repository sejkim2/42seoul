#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
    std::cout << "ScalarConverter Default Constructor Called" << '\n';
}

ScalarConverter::~ScalarConverter(void)
{
    std::cout << "ScalarConverter Default Destructor Called" << '\n';
}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
    *this = copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj)
{
    if (&obj != this)
    {
    }
    return (*this);
}

void ScalarConverter::convert(std::string literal)
{
    Literal checkLiteral;
    char *end;

    
    // std::string convertChar;
    // std::string convertInt;
    // std::string convertFloat;
    // std::string convertDouble;
    

    // if (literal.compare("-inff") == 0)
    // {
        
    // }
    // else if (literal.compare("+inff") == 0)
    // {

    // }
    // else if (literal.compare("nanf") == 0)
    // {

    // }
    // else if (literal.compare("-inf") == 0)
    // {

    // }
    // else if (literal.compare("+inf") == 0)
    // {
    //     convertChar = "impossible";
    //     convertInt = "+inf";
    //     convertFloat = "+inff";
    //     convertDouble = "nan";
    // }
    // else if (literal.compare("nan") == 0)
    // {
    //     convertChar = "impossible";
    //     convertInt = "impossible";
    //     convertFloat = "nanf";
    //     convertDouble = "nan";
    // }
    // else
    // {

    // }
    
}
