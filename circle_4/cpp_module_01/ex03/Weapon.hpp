#ifndef _WEAPON
# define _WEAPON

# include <string>

class Weapon
{
    private:
        std::string type;
    public:
        std::string& getType() const;
};

#endif