#include "ZombieHorde.cpp"

int main(void)
{
    std::string name;
    int         N;

    std::cin >> name;
    std::cin >> N;

    Zombie *zombieArr = zombieHorde(N, name);
    
    for(int i = 0; i<N; i++)
        zombieArr[i].announce();

    delete [] zombieArr;
}