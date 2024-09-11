#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
    // std::cout << "BitcoinExchange Default Constructor Called" << '\n';
}

BitcoinExchange::~BitcoinExchange(void)
{
    // std::cout << "BitcoinExchange Default Destructor Called" << '\n';
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
    *this = copy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj)
{
    if (&obj != this)
    {
    }
    return (*this);
}

BitcoinExchange::BitcoinExchange(const std::string& filename)
: filename(filename)
{
}

void BitcoinExchange::fileOpen(void)
{
    std::ifstream file("data.csv");
    std::string line;
    std::map<std::string, std::string> btcPrice;

    if (!file.is_open())
        throw BitcoinExchange::FileOpenException();

    while (std::getline(file, line))
    {
        size_t delimeter = line.find(",");
        std::string date = line.substr(0, delimeter);
        std::string value = line.substr(delimeter + 1, line.length());

        btcPrice[date] = value;
    }

    std::ifstream input(this->filename);
    if (!input.is_open())
        throw BitcoinExchange::FileOpenException();
    
    while (std::getline(input, line))
    {
        size_t delimeter = line.find("|");
        std::string date = line.substr(0, delimeter);
        std::string value = line.substr(delimeter + 1, line.length());

        std::map<std::string, std::string>::iterator it = btcPrice.upper_bound(date);
        if (it != btcPrice.begin())
            it--;
        std::cout << date << " => " << value << " = " << it->second << "*" << value << '\n';

        //todo1 : Error
        //todo2 : 윤년
    }
}

const char* BitcoinExchange::FileOpenException::what() const throw()
{
    return "could not open file.";
}