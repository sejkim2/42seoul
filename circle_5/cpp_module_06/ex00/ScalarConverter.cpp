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

convertStruct ScalarConverter::handleNanInff(std::string literal)
{
    if (literal.compare("-inff") == 0)
        return convertStruct{"impossible", "impossible", "-inf", "-inff"};
    else if (literal.compare("+inff") == 0)
        return convertStruct{"impossible", "impossible", "inf", "inff"};
    else if (literal.compare("nanf") == 0)
        return convertStruct{"impossible", "impossible", "nanf", "nan"};
    else if (literal.compare("-inf") == 0)
        return convertStruct{"impossible", "impossible", "-inf", "-inff"};
    else if (literal.compare("+inf") == 0)
        return convertStruct{"impossible", "impossible", "inff", "inf"};
    else
        return convertStruct{"impossible", "impossible", "nanf", "nan"};
}

//nan : 부동소수점 체계에서 사용
//지수부 비트가 모두 1, 가수부 비트는 최소 하나는 1
//수학적으로 정의되지 않은 결과를 나타내기 위해 사용

//inf : 부동소수점 체계에서 사용
//지수부 비트는 모두 1, 가수부 비트는 모두 0
//매우 큰 수를 나타내기 위해 사용
void ScalarConverter::convert(std::string literal)
{
    int flag = 0;
    convertStruct cs;
    std::string convertChar;
    std::string convertInt;
    std::string convertFloat;
    std::string convertDouble;
    
    std::string keyword[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};

    for(int i = 0; i<6; i++)
    {
        if (literal.compare(keyword[i]) == 0)
        {
            cs = handleNanInff(literal);
            flag = 1;
            break ;
        }
    }
    
    if (!flag)
    {
        if (literal.length() == 1)
        {
            char tmp = literal[0];
            if (tmp >= 32 && tmp <= 126)
                convertChar = tmp;
            else
                convertChar = "Non displayable";

            convertInt = static_cast<int>(tmp);
            convertFloat = literal + ".0f";
            convertDouble = literal + ".0";
        }
        size_t findptr = literal.find(".");
        int floatflag = 0;

        // int
        if (findptr == std::string::npos)
        {
            for (size_t i = 0; i < literal.length(); i++)
            {
                if (i == 0 && (literal[i] == '-' || literal[i] == '+') && literal.length() != 1)
                    continue;
                if (!std::isdigit(literal[i]))
                {
                    std::cout << "is not number\n";
                    return;
                }
            }
            int tmp = atoi(literal.c_str());
            if (tmp >= 32 && tmp <= 126)
                convertChar = static_cast<char>(tmp);
            else
                convertChar = "Non displayable";

            convertInt = literal;
            convertFloat = literal + ".0f";
            convertDouble = literal + ".0";
        }
        else
        {
            for (size_t i = 0; i < findptr; i++)
            {
                if (i == 0 && (literal[i] == '-' || literal[i] == '+') && literal.length() != 1)
                    continue;
                if (!std::isdigit(literal[i]))
                {
                    std::cout << "is not number\n";
                    return;
                }
            }
            if (!std::isdigit(literal[findptr - 1]))
            {
                std::cout << "is not number 2 \n";
                return;
            }
            if (findptr + 1 == literal.length())
            {
                std::cout << "is not number 2 \n";
                return;
            }
            if (literal[findptr + 1] == 'f')
            {
                std::cout << "is not number 2 \n";
                return;
            }
            for (size_t i = findptr + 1; i < literal.length(); i++)
            {
                if (!std::isdigit(literal[i]))
                {
                    if (literal[i] == 'f' && i == literal.length() - 1)
                    {
                        floatflag = 1;
                        break;
                    }
                    else
                    {
                        std::cout << "is not number 3 \n";
                        return;
                    }
                }
            }
            if (floatflag == 1)
            {
                float tmp = atof(literal.c_str());
                if (tmp >= 32 && tmp <= 126)
                    convertChar = static_cast<char>(tmp);
                else
                    convertChar = "Non displayable";

                convertInt = literal.substr(0, literal.find("."));
                convertFloat = literal;
                convertDouble = literal.substr(0, literal.find("f"));
            }
            else
            {
                char *endptr;
                double tmp = strtod(literal.c_str(), &endptr);
                if (tmp >= 32 && tmp <= 126)
                    convertChar = static_cast<char>(tmp);
                else
                    convertChar = "Non displayable";

                convertInt = literal.substr(0, literal.find("."));
                convertFloat = literal + "f";
                convertDouble = literal;
            }
        }
    }
    std::cout << "char: " << convertChar << '\n';
    std::cout << "int: " << convertInt << '\n';
    std::cout << "float: " << convertFloat << '\n';
    std::cout << "double: " << convertDouble << '\n';
}
