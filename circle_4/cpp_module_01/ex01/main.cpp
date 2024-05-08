#include "Zombie.hpp"

// void leaks()
// {
//     system("leaks ex01");
// }

int main(void)
{
    // atexit(leaks);
    int N = 4;

    Zombie *zombieArr = zombieHorde(N, "zombie1");
    
    for(int i = 0; i<N; i++)
        zombieArr[i].announce();

    delete [] zombieArr;
}
