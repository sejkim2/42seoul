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

        if (isValidDate(date) == false)
        {
            std::cout << "Error: bad input => " << date << '\n';
            continue;
        }

        std::stringstream ss(value);
        double price;
        ss >> price;
        if (price < -2147483648 || price > 2147483647)
        {
            std::cout << "Error: too large a number." << '\n';
            continue;
        }
        else if (price < 0)
        {
            std::cout << "Error: not a positive number." << '\n';
            continue;
        }

        std::map<std::string, std::string>::iterator it = btcPrice.upper_bound(date);
        if (it != btcPrice.begin())
            it--;

        std::stringstream ss2(it->second);
        double price2;
        ss2 >> price2;

        std::cout << date << " => " << value << "= " << price * price2 << '\n';
            
        //todo3 : upper_bound가 end일 때

    }
}

const char* BitcoinExchange::FileOpenException::what() const throw()
{
    return "could not open file.";
}

const char* BitcoinExchange::NotNumberException::what() const throw()
{
    return "not a number.";
}

const char* BitcoinExchange::NotInvalidException::what() const throw()
{
    return "not invalid number.";
}

bool BitcoinExchange::isLeapYear(int year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int BitcoinExchange::daysInMonth(int month, int year) 
{
    switch (month) 
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 0;
    }
}

bool BitcoinExchange::isValidDate(const std::string &dateStr) 
{
    int year, month, day;
    char delimiter1, delimiter2;

    std::istringstream dateStream(dateStr);
    dateStream >> year >> delimiter1 >> month >> delimiter2 >> day;

    if (delimiter1 != '-' || delimiter2 != '-' || dateStream.fail()) 
        return false;

    if (year < 1 || month < 1 || month > 12 || day < 1 || day > daysInMonth(month, year)) 
        return false;

    return true;
}