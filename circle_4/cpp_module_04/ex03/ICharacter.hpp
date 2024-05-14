#ifndef _ICHARACTER
# define _ICHARACTER

# include "AMateria.hpp"
# define MAX_SLOT_SIZE 4
# define FLOOR_SIZE 1000

class ICharacter
{
    public:
        virtual ~ICharacter() {}
        virtual std::string const & getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
};

#endif
