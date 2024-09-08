#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error: could not open file." << '\n';
        return (1);
    }
    BitcoinExchange("data.csv");
}