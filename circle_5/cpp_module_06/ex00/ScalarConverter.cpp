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

//nan : 부동소수점 체계에서 사용
//지수부 비트가 모두 1, 가수부 비트는 최소 하나는 1
//수학적으로 정의되지 않은 결과를 나타내기 위해 사용

//inf : 부동소수점 체계에서 사용
//지수부 비트는 모두 1, 가수부 비트는 모두 0
//매우 큰 수를 나타내기 위해 사용
void ScalarConverter::convert(std::string literal)
{
    // Literal checkLiteral;
    // char *end;

    std::string convertChar;
    std::string convertInt;
    std::string convertFloat;
    std::string convertDouble;
    
    if (literal.compare("-inff") == 0)
    {
        convertChar = "impossible";
        convertInt = "impossible";
        convertFloat = "-inf";
        convertDouble = "-inff";
    }
    else if (literal.compare("+inff") == 0)
    {
        convertChar = "impossible";
        convertInt = "impossible";
        convertFloat = "inf";
        convertDouble = "inff";
    }
    else if (literal.compare("nanf") == 0)
    {
        convertChar = "impossible";
        convertInt = "impossible";
        convertFloat = "nanf";
        convertDouble = "nan";
    }
    else if (literal.compare("-inf") == 0)
    {
        convertChar = "impossible";
        convertInt = "impossible";
        convertFloat = "-inf";
        convertDouble = "-inff";
    }
    else if (literal.compare("+inf") == 0)
    {
        convertChar = "impossible";
        convertInt = "impossible";
        convertFloat = "inff";
        convertDouble = "inf";
    }
    else if (literal.compare("nan") == 0)
    {
        convertChar = "impossible";
        convertInt = "impossible";
        convertFloat = "nanf";
        convertDouble = "nan";
    }
    else
    {
        
        // 1. int
        // int tmp = atoi(literal.c_str());
        // if (tmp >= 32 && tmp <= 126)
        //     convertChar = static_cast<char>(tmp);
        // else
        //     convertChar = "Non displayable";
        
        // convertInt = literal;
        // convertFloat = literal + ".0f";
        // convertDouble = literal + ".0";

        // // 2. float
        // float tmp = atof(literal.c_str());
        // if (tmp >= 32 && tmp <= 126)
        //     convertChar = static_cast<char>(tmp);
        // else
        //     convertChar = "Non displayable";
        
        // convertInt = literal.substr(0, literal.find("."));
        // convertFloat = literal;
        // convertDouble = literal.substr(0, literal.find("f"));
        
        // 3. double
        // char *endptr;
        // double tmp = strtod(literal.c_str(), &endptr);
        // if (tmp >= 32 && tmp <= 126)
        //     convertChar = static_cast<char>(tmp);
        // else
        //     convertChar = "Non displayable";
        
        // convertInt = literal.substr(0, literal.find("."));
        // convertFloat = literal + "f";
        // convertDouble = literal;

        // 4. else : string

            // std::cout << "erorr!!" << '\n';
            // return;
    }
    std::cout << "char: " << convertChar << '\n';
    std::cout << "int: " << convertInt << '\n';
    std::cout << "float: " << convertFloat << '\n';
    std::cout << "double: " << convertDouble << '\n';
}
