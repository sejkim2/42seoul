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
            return (false);
    }
    return (true);
}

bool ScalarConverter::validateNanInf(std::string literal)
{
    std::string keyword[8] = {"-inff", "+inff", "inff", "nanf", "-inf", "+inf", "inf", "nan"};

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

void ScalarConverter::convert(std::string literal)
{
    convertStruct cs("", "", "", "");

    if (literal.length() == 0)
        setAllImpossible(cs);
    else if (validateNanInf(literal) == true)
        return;
    else if (literal.length() == 1 && !(literal[0] >= '0' && literal[0] <= '9'))
        handleChar(literal, cs);
    else
    {
        size_t findptr = literal.find(".");

        if (findptr == std::string::npos)
        {
            if (handleInt(literal, cs) == false)
                setAllImpossible(cs);
        }
        else
        {
            int floatFlag = 0;
            if (isDecimal(literal, findptr, floatFlag) == false)
                setAllImpossible(cs);
            else if (floatFlag == 1)
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
    cs.ch = literal[0];
    cs.n = static_cast<int>(cs.ch);
    cs.f = static_cast<float>(cs.ch);
    cs.d = static_cast<double>(cs.ch);

    std::stringstream ss;

    cs.convertChar = "\'" + literal + "\'";

    ss << static_cast<int>(literal[0]);
    cs.convertInt = ss.str();

    cs.convertFloat = cs.convertInt + ".0f";
    cs.convertDouble = cs.convertInt + ".0";
    
    return (true);
}

bool ScalarConverter::validateDoubleOverflow(std::string literal)
{
    double d;

    d = strtod(literal.c_str(), 0);
    if (d > std::numeric_limits<double>::max() || d < std::numeric_limits<double>::lowest() || d == std::numeric_limits<double>::infinity())
        return (true);
    else
        return (false);
}

bool ScalarConverter::handleInt(std::string literal, convertStruct& cs)
{
    if (isNumber(literal, literal.length()) == false || validateDoubleOverflow(literal) == true)
        return (setAllImpossible(cs));

    cs.d = strtod(literal.c_str(), 0);
    cs.f = static_cast<float>(cs.d);
    cs.n = static_cast<int>(cs.d);
    cs.ch = static_cast<char>(cs.d);

    if ((cs.d >= 0 && cs.d <= 31) || cs.d == 127)
        cs.convertChar = "Non displayable";
    else if (cs.d >= 32 && cs.d <= 126)
        cs.convertChar = "'" + std::string(1, cs.ch) + "'";
    else
        cs.convertChar = "impossible";

    if (cs.d > std::numeric_limits<int>::max() || cs.d < std::numeric_limits<int>::lowest())
        cs.convertInt = "impossible";
    else
        cs.convertInt = literal;

    if (cs.d > std::numeric_limits<float>::max() || cs.d < std::numeric_limits<float>::lowest())
        cs.convertFloat = "impossible";
    else
        cs.convertFloat = literal + ".0f";  //diff

    cs.convertDouble = literal + ".0";
    return (true);
}

bool ScalarConverter::handleFloat(std::string literal, convertStruct &cs)
{
    if (validateDoubleOverflow(literal) == true)
        return (setAllImpossible(cs));

    cs.d = strtod(literal.c_str(), 0);
    cs.f = static_cast<float>(cs.d);
    cs.n = static_cast<int>(cs.d);
    cs.ch = static_cast<char>(cs.d);

    if ((cs.d >= 0 && cs.d <= 31) || cs.d == 127)
        cs.convertChar = "Non displayable";
    else if (cs.d >= 32 && cs.d <= 126)
        cs.convertChar = "'" + std::string(1, cs.ch) + "'";
    else
        cs.convertChar = "impossible";

    if (cs.d > std::numeric_limits<int>::max() || cs.d < std::numeric_limits<int>::lowest())
        cs.convertInt = "impossible";
    else
        cs.convertInt = literal.substr(0, literal.find("."));   //diff

    if (cs.d > std::numeric_limits<float>::max() || cs.d < std::numeric_limits<float>::lowest())
        cs.convertFloat = "impossible";
    else
        cs.convertFloat = literal;    //diff

    cs.convertDouble = literal.substr(0, literal.find("f"));    //diff
    if (cs.convertDouble[(cs.convertDouble).length() - 1] == '.')
        cs.convertDouble.append("0");
    return (true);
}

bool ScalarConverter::handleDouble(std::string literal, convertStruct &cs)
{
    if (validateDoubleOverflow(literal) == true)
        return (setAllImpossible(cs));

    cs.d = strtod(literal.c_str(), 0);
    cs.f = static_cast<float>(cs.d);
    cs.n = static_cast<int>(cs.d);
    cs.ch = static_cast<char>(cs.d);

    if ((cs.d >= 0 && cs.d <= 31) || cs.d == 127)
        cs.convertChar = "Non displayable";
    else if (cs.d >= 32 && cs.d <= 126)
        cs.convertChar = "'" + std::string(1, cs.ch) + "'";
    else
        cs.convertChar = "impossible";

    if (cs.d > std::numeric_limits<int>::max() || cs.d < std::numeric_limits<int>::lowest())
        cs.convertInt = "impossible";
    else
        cs.convertInt = literal.substr(0, literal.find("."));   //diff

    if (cs.d > std::numeric_limits<float>::max() || cs.d < std::numeric_limits<float>::lowest())
        cs.convertFloat = "impossible";
    else
        cs.convertFloat = literal + "f";    //diff

    cs.convertDouble = literal;
    return (true);
}

bool ScalarConverter::isDecimal(std::string literal, size_t findptr, int& floatFlag)
{
    if (isNumber(literal, findptr) == false)
        return (false);
    if (literal[0] == '.') //.42
        return (false);
    if (findptr + 1 == literal.length()) // 42.
        return (false);
    // if (literal[findptr + 1] == 'f') // 42.f
    //     return (false);
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
                return (false);
        }
    }
    return (true);
}

bool ScalarConverter::setAllImpossible(convertStruct &cs)
{
    cs.convertChar = "impossible";
    cs.convertInt = "impossible";
    cs.convertFloat = "impossible";
    cs.convertDouble = "impossible";
    return (false);
}