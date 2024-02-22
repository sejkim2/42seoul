#include "MyIostream.hpp"

void    MyIostream::ioError()
{
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(BUF_SIZE, '\n');
        std::cout << "cin error!" << '\n';
        exit(1);
    }
}