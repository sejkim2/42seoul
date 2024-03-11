#ifndef _ZOMBIE
# define _ZOMBIE

# include <string>
# include <iostream>
# include <stdlib.h>

class Zombie
{
    private:
        std::string name;
    public:
        void setName(std::string name);
        void announce(void);
        ~Zombie();
};

Zombie*	zombieHorde(int N, std::string name);

#endif
