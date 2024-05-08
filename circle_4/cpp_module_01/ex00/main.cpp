#include "Zombie.hpp"

int main(void)
{
    Zombie *zombie = newZombie("zombie1");
    zombie->announce();

    randomChump("zombie2");
    delete zombie;
}
