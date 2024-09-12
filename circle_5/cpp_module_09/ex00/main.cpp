#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error: could not open file." << '\n';
        (void) argv;
        return (1);
    }
    BitcoinExchange btc("input.txt");
    btc.fileOpen();
}