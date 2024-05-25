#include <iostream>

void func(int n)
{
    if (n < 0)
        throw (n);
    else if (n == 0)
        throw ("is zero");
}

int main(void)
{
    int n;
    std::cin >> n;

    try {
        func(n);
        std::cout << "is plus : " << n << '\n';
    }
    catch(...) {
        
    }
    std::cout << "end";
}