#ifndef _SCALARCONVERTER_HPP__
# define _SCALARCONVERTER_HPP__

# include <iostream>

enum Literal {
    NON_LITERAL,
    CHAR_LITERAL,
    INT_LITERAL,
    FLOAT_LITERAL,
    MINUS_INFF_LITERAL,
    PLIS_INFF_LITERAL,
    NANF_LITERAL,
    DOUBLE_LITERAL,
    MINUS_INF_LITERAL,
    PLUS_INF_LITERAL,
    NAN_LITERAL
};

struct convertStruct {
    std::string charValue;
    std::string intValue;
    std::string floatValue;
    std::string doubleValue;

    convertStruct(std::string charVal, std::string intVal, std::string floatVal, std::string doubleVal)
        : charValue(charVal), intValue(intVal), floatValue(floatVal), doubleValue(doubleVal) {}
};


class ScalarConverter
{
    public:
        ~ScalarConverter(void);
        ScalarConverter(const ScalarConverter& copy);
        ScalarConverter& operator=(const ScalarConverter& obj);

        static void convert(std::string literal);
    
    private:
        ScalarConverter(void);
        static convertStruct handleNanInff(std::string literal);
};

#endif