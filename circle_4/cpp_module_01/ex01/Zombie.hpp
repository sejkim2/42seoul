#ifndef _ZOMBIE
# define _ZOMBIE

# include <iostream>
# include <string>

class Zombie
{
    private:
        std::string name;
    public:
        Zombie(void);
        Zombie(std::string name);
        ~Zombie();
        void    setName(std::string name);
        void    announce(void);
};

#endif