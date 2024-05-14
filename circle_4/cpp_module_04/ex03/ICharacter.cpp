#include "ICharacter.hpp"

ICharacter::ICharacter(void) : index(0), countAMateria(0), name("empty")
{
    for(int i = 0; i < MAX_SLOT_SIZE; i++)
        this->slot[i] = 0;
    
    for(int i = 0; i < FLOOR_SIZE; i++)
        this->floor[i] = 0;
    
    std::cout << "this is ICharacter constructor" << '\n';
}

ICharacter::~ICharacter(void)
{
    std::cout << "this is ICharacter desstructor" << '\n';
}
        
ICharacter::ICharacter(const ICharacter& iCharacter)
{
    *this = iCharacter;
}

ICharacter& ICharacter::operator=(const ICharacter& iCharacter)
{
    if (&iCharacter == this)
        return (*this);

    return (*this);
}

ICharacter::ICharacter(std::string name) : index(0), countAMateria(0), name(name)
{
    for(int i = 0; i < MAX_SLOT_SIZE; i++)
        this->slot[i] = 0;
    
    for(int i = 0; i < FLOOR_SIZE; i++)
        this->floor[i] = 0;
}

std::string const & ICharacter::getName() const
{
    return (this->name);
}

void ICharacter::equip(AMateria* m)
{
    if (getIsFull() == true)
    {
        std::cout << "inventory is full status" << '\n';
        return;
    }

    slot[index] = m;
    index = (index + 1) % MAX_SLOT_SIZE;
    countAMateria++;
}

void ICharacter::unequip(int idx)
{

}

void ICharacter::use(int idx, ICharacter& target)
{

}

bool ICharacter::getIsFull(void) const
{
    if (countAMateria == MAX_SLOT_SIZE)
        return (true);
    else
        return (false);
}