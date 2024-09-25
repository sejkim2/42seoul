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

BitcoinExchange::BitcoinExchange(std::string filename)
: filename(filename)
{
}

std::map<std::string, std::string> BitcoinExchange::parseDataFile(void)
{
    std::ifstream file("data.csv");
    std::string line;
    std::map<std::string, std::string> btcPrice;

    if (!file.is_open())
        throw BitcoinExchange::FileOpenException();
    
    while (std::getline(file, line))
    {
        std::string::size_type delimeter = line.find(",");
        std::string date = line.substr(0, delimeter);
        std::string value = line.substr(delimeter + 1);

        btcPrice[date] = value;
    }

    return (btcPrice);
}

bool BitcoinExchange::string2double(std::string value, double& price)
{
    std::stringstream ss(value);
    ss >> price;

    if (price < -2147483648 || price > 2147483647)
    {
        std::cout << "Error: too large a number." << '\n';
        return (false);
    }
    if (price < 0)
    {
        std::cout << "Error: not a positive number." << '\n';
        return (false);
    }
    return (true);
}

void BitcoinExchange::parseInputFile(std::map<std::string, std::string>& btcPrice)
{
    std::string line;
    std::ifstream input(this->filename);

    if (!input.is_open())
        throw BitcoinExchange::FileOpenException();
    
    std::getline(input, line);
    if (line.compare("date | value") != 0)
        throw BitcoinExchange::InputFileFormatException();

    while (std::getline(input, line))
    {
        std::string::size_type delimeter = line.find("|");
        std::string date = trim(line.substr(0, delimeter));
        std::string value = trim(line.substr(delimeter + 1));
        double price;

        if (isValidDate(date) == false)
            continue;

        if (string2double(value, price) == false)
            continue;

        std::map<std::string, std::string>::iterator it = btcPrice.upper_bound(date);
        if (it != btcPrice.begin())
            it--;

        std::stringstream ss2(it->second);
        double price2;
        ss2 >> price2;

        std::cout << date << " => " << value << " = " << price * price2 << '\n';
    }
}

void BitcoinExchange::calculateBitcoin(void)
{
    std::map<std::string, std::string> btcPrice = parseDataFile();
    parseInputFile(btcPrice);
}

const char* BitcoinExchange::FileOpenException::what() const throw()
{
    return "could not open file.\n";
}

const char* BitcoinExchange::NotNumberException::what() const throw()
{
    return "not a number.\n";
}

const char* BitcoinExchange::NotInvalidException::what() const throw()
{
    return "not invalid number.\n";
}

const char* BitcoinExchange::InputFileFormatException::what() const throw()
{
    return "input file wrong format.\n";
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
    {
        std::cout << "Error: bad input => " << dateStr << '\n';
        return (false);
    }

    if (year < 2009 || (year == 2009 && (month < 1 || (month == 1 && day < 2))))
    {
        std::cout << "Error: date must be on or after 2009-01-02 => " << dateStr << '\n';
        return false;
    }

    if (year < 1 || month < 1 || month > 12 || day < 1 || day > daysInMonth(month, year))
    {
        std::cout << "Error: bad input => " << dateStr << '\n';
        return (false);
    }
    return true;
}

std::string BitcoinExchange::trim(const std::string& str) 
{
    std::string::size_type start = str.find_first_not_of(" \t\n\r\f\v");
    if (start == std::string::npos)
        return "";
    
    std::string::size_type end = str.find_last_not_of(" \t\n\r\f\v");
    
    return str.substr(start, end - start + 1);
}