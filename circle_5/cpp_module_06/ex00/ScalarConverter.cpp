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
        return convertStruct("impossible", "impossible", "-inf", "-inff");
    else if (literal.compare("+inff") == 0 || literal.compare("inff") == 0)
        return convertStruct("impossible", "impossible", "inf", "inff");
    else if (literal.compare("nanf") == 0)
        return convertStruct("impossible", "impossible", "nanf", "nan");
    else if (literal.compare("-inf") == 0)
        return convertStruct("impossible", "impossible", "-inf", "-inff");
    else if (literal.compare("+inf") == 0 || literal.compare("inf") == 0)
        return convertStruct("impossible", "impossible", "inff", "inf");
    else
        return convertStruct("impossible", "impossible", "nanf", "nan");
}

bool ScalarConverter::isNumber(std::string literal, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        if (i == 0 && (literal[i] == '-' || literal[i] == '+') && literal.length() != 1)
            continue;
        if (!std::isdigit(literal[i]))
        {
            std::cout << "is not number 1\n";
            return (false);
        }
    }
    return (true);
}

bool ScalarConverter::validateNanInf(std::string literal)
{
    std::string keyword[8] = {"-inff", "+inff", "inff", "nanf", "-inf", "+inf", "inf", "nan"};

    //inf, nan
    for(int i = 0; i<8; i++)
    {
        if (literal.compare(keyword[i]) == 0)
        {
            printValue(handleNanInff(literal));
            return (true);
        }
    }
    return (false);
}
        
//nan : 부동소수점 체계에서 사용
//지수부 비트가 모두 1, 가수부 비트는 최소 하나는 1
//수학적으로 정의되지 않은 결과를 나타내기 위해 사용
//자기 자신과의 비교가 항상 false

//inf : 부동소수점 체계에서 사용
//지수부 비트는 모두 1, 가수부 비트는 모두 0
//매우 큰 수를 나타내기 위해 사용
void ScalarConverter::convert(std::string literal, int argc)
{
    convertStruct cs("", "", "", "");

    if (argc != 2)
    {
        std::cout << "not invalid argument" << '\n';
        return;
    }
    //inf, nan
    if (validateNanInf(literal) == true)
        return;
    // char
    if (literal.length() == 1 && !(literal[0] >= '0' && literal[0] <= '9'))
        handleChar(literal, cs);
    else
    {
        size_t findptr = literal.find(".");

        // int (소수점 없음)
        if (findptr == std::string::npos)
        {
            if (handleInt(literal, cs) == false)
                return;
        }
        // float or double (소수점 있음)
        else
        {
            int floatFlag = 0;
            if (isDecimal(literal, findptr, floatFlag) == false)
                return;
            if (floatFlag == 1)
                handleFloat(literal, cs);
            else
                handleDouble(literal, cs);
        }
    }

    printValue(cs);
}

void ScalarConverter::printValue(convertStruct cs)
{
    std::cout << "char: " << cs.convertChar << '\n';
    std::cout << "int: " << cs.convertInt << '\n';
    std::cout << "float: " << cs.convertFloat << '\n';
    std::cout << "double: " << cs.convertDouble << '\n';
}

bool ScalarConverter::handleChar(std::string literal, convertStruct& cs)
{
    std::stringstream ss;

    cs.convertChar = "\'" + literal + "\'";

    ss << static_cast<int>(literal[0]);
    cs.convertInt = ss.str();

    cs.convertFloat = cs.convertInt + ".0f";
    cs.convertDouble = cs.convertInt + ".0";
    
    return (true);
}

bool ScalarConverter::handleInt(std::string literal, convertStruct& cs)
{
    int num;

    // is number??
    if (isNumber(literal, literal.length()) == false)
        return (false);

    num = atoi(literal.c_str());
    if (num >= 32 && num <= 126)
        cs.convertChar = "'" + std::string(1, static_cast<char>(num)) + "'";
    else
        cs.convertChar = "Non displayable";

    cs.convertInt = literal;
    cs.convertFloat = literal + ".0f";
    cs.convertDouble = literal + ".0";
    
    return (true);
}

bool ScalarConverter::handleFloat(std::string literal, convertStruct &cs)
{
    float tmp = atof(literal.c_str());

    if (tmp >= 32 && tmp <= 126)
        cs.convertChar = "'" + std::string(1, static_cast<char>(tmp)) + "'";
    else
        cs.convertChar = "Non displayable";

    cs.convertInt = literal.substr(0, literal.find("."));
    cs.convertFloat = literal;
    cs.convertDouble = literal.substr(0, literal.find("f"));

    return (true);
}

bool ScalarConverter::handleDouble(std::string literal, convertStruct &cs)
{
    char *endptr;
    double tmp = strtod(literal.c_str(), &endptr);

    if (tmp >= 32 && tmp <= 126)
        cs.convertChar = "'" + std::string(1, static_cast<char>(tmp)) + "'";
    else
        cs.convertChar = "Non displayable";

    cs.convertInt = literal.substr(0, literal.find("."));
    cs.convertFloat = literal + "f";
    cs.convertDouble = literal;

    return (true);
}

bool ScalarConverter::isDecimal(std::string literal, size_t findptr, int& floatFlag)
{
    // is number?
    if (isNumber(literal, findptr) == false)
        return (false);
    if (literal[0] == '.') //.42
    {
        std::cout << "is not number 2 \n";
        return (false);
    }
    if (findptr + 1 == literal.length()) // 42.
    {
        std::cout << "is not number 3 \n";
        return (false);
    }
    if (literal[findptr + 1] == 'f') // 42.f
    {
        std::cout << "is not number 4 \n";
        return (false);
    }
    for (size_t i = findptr + 1; i < literal.length(); i++)
    {
        if (!std::isdigit(literal[i]))
        {
            if (literal[i] == 'f' && i == literal.length() - 1)
            {
                floatFlag = 1;
                break;
            }
            else
            {
                std::cout << "is not number 5 \n";
                return (false);
            }
        }
    }
    return (true);
}