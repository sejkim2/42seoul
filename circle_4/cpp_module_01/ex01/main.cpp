#include "Zombie.hpp"

void leaks()
{
    system("leaks ex01");
}

int main(void)
{
    atexit(leaks);
    std::string name;
    int         N;

    std::cout << "input zombie name >> ";
    std::getline(std::cin, name);
    std::cout << "input zombie count >>";
    std::cin >> N;

    Zombie *zombieArr = zombieHorde(N, name);
    
    for(int i = 0; i<N; i++)
        zombieArr[i].announce();

    delete [] zombieArr;
    exit(1);
}
