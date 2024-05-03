#include "MyIostream.hpp"

void    MyIostream::ioError()
{
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "cin error!" << '\n';
        std::exit(1);
    }
}
