#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error: could not open file." << '\n';
        return (1);
    }
    try {
        BitcoinExchange btc(argv[1]);
        btc.calculateBitcoin();
    } catch (std::exception& e) {
        std::cout << e.what();
    }
}