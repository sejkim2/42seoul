#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int index = 1;
    switch (index)
    {
        case 0:
            std::cout << "is 0";
        case 1:
            std::cout << "is 1";
        case 2:
            std::cout << "is 2";
        case 3:
            std::cout << "is 3";
        default:
            std::cout << "default";
            break;
    }
}