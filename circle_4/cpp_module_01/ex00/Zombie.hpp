#ifndef _ZOMBIE
# define _ZOMBIE

# include <string>
# include <iostream>

class Zombie
{
    private:
        std::string name;
    public:
        void setName(std::string name);
        void announce(void);
        ~Zombie();
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
