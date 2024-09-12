#ifndef _SCALARCONVERTER_HPP__
# define _SCALARCONVERTER_HPP__

# include <iostream>
# include <sstream>
# include <limits>

struct convertStruct {
    char ch;
    int n;
    float f;
    double d;
    std::string convertChar;
    std::string convertInt;
    std::string convertFloat;
    std::string convertDouble;

    convertStruct(std::string charVal, std::string intVal, std::string floatVal, std::string doubleVal)
        : convertChar(charVal), convertInt(intVal), convertFloat(floatVal), convertDouble(doubleVal) {}
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
        static bool isNumber(std::string literal, std::string::size_type len);
        static void printValue(convertStruct cs);
        static bool handleChar(std::string literal, convertStruct& cs);
        static bool handleInt(std::string literal, convertStruct& cs);
        static bool handleFloat(std::string literal, convertStruct& cs);
        static bool handleDouble(std::string literal, convertStruct& cs);
        static bool isDecimal(std::string literal, std::string::size_type findptr, int& floatFlag);
        static bool validateNanInf(std::string literal);

        static bool validateDoubleOverflow(std::string literal);
        static bool setAllImpossible(convertStruct &cs);

};

#endif