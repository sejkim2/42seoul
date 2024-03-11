#include "MyStream.hpp"

int main(int argc, char **argv)
{
    if (argc == 4)
    {
        MyStream ms(argv);

        if (ms.getOpenSucces())
        {
            ms.setOrigin();
            ms.replaceString();
        }
        else
            std::cout << "ifstream error!" << '\n';
    }
    else
        std::cout << "argument error!" << '\n';
}
