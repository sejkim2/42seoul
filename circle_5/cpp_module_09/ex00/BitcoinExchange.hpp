#ifndef _BITCOINEXCHANGE_HPP__
# define _BITCOINEXCHANGE_HPP__

# include <iostream>
# include <sstream>
# include <fstream>
# include <map>

class BitcoinExchange
{
    public:
        ~BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange& copy);
        BitcoinExchange& operator=(const BitcoinExchange& obj);

        BitcoinExchange(std::string filename);
    
    class FileOpenException : public std::exception
    {
        public:
            const char* what() const throw();
    };

    class NotNumberException : public std::exception
    {
        public:
            const char* what() const throw();
    };

    class NotInvalidException : public std::exception
    {
        public:
            const char* what() const throw();
    };

    class InputFileFormatException : public std::exception
    {
        public:
            const char* what() const throw();
    };

        void calculateBitcoin(void);
    private:
        BitcoinExchange(void);
        bool isLeapYear(int year);
        int daysInMonth(int month, int year);
        bool isValidDate(const std::string &dateStr);
        std::map<std::string, std::string> parseDataFile(void);
        void parseInputFile(std::map<std::string, std::string>& btcPrice);
        bool string2double(std::string value, double& price);
        std::string trim(const std::string& str);

        std::string filename;
};

#endif
