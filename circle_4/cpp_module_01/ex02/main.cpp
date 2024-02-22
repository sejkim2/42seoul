#include <iostream>
#include <string>

int main(void)
{
    std::string stringVAL = "HI THIS IS BRAIN";
    std::string* stringPTR = &stringVAL;
    std::string& stringREF = stringVAL;

    std::cout << "The memory address of the string variable : " << &stringVAL << '\n';
    std::cout << "The memory address held by stringPTR : " << stringPTR << '\n';
    std::cout << "The memory address held by stringREF : " << &stringREF << '\n';

    std::cout << "The value of the string variable : " << stringVAL << '\n';
    std::cout << "The value pointed to by stringPTR : " << *stringPTR << '\n';
    std::cout << "The value pointed to by stringREF : " << stringREF << '\n';
}