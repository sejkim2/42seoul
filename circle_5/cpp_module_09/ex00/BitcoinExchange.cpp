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
        std::cout << "file open error"; //throw

    while (std::getline(file, line))
    {
        size_t delimeter = line.find(",");
        std::string key = line.substr(0, delimeter);
        std::string value = line.substr(delimeter + 1, line.length());

        btcPrice[key] = value;
    }

    std::ifstream input(this->filename);
    if (!input.is_open())
        std::cout << "file open error";
    
    while (std::getline(input, line))
    {
        size_t delimeter = line.find("|");
        std::string data = line.substr(0, delimeter);
        std::string value = line.substr(delimeter + 1, line.length());
    }

}
