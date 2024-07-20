#include <iostream>
using namespace std;

int main(void)
{
    int num = 0x040204; 
    char* ptr = reinterpret_cast<char*>(&num); 
    std::cout << static_cast<int>(*(ptr + 2)) << std::endl;
}