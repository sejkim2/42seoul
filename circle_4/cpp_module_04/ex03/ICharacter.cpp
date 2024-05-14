#include "ICharacter.hpp"

ICharacter::ICharacter(void) : 
slot_index(0), countAMateria(0), floor_index(0), countFloorAMateria(0), name("empty")
{
    for(int i = 0; i < MAX_SLOT_SIZE; i++)
        this->slot[i] = 0;
    
    for(int i = 0; i < FLOOR_SIZE; i++)
        this->floor[i] = 0;
    
    std::cout << "this is ICharacter constructor" << '\n';
}

ICharacter::~ICharacter(void)
{
    for(int i = 0; i < countAMateria; i++)
        delete slot[i];
    for(int i = 0; i < countFloorAMateria; i++)
        delete floor[i];
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

    for(int i = 0; i < countAMateria; i++)
        delete slot[i];
    for(int i = 0; i < countFloorAMateria; i++)
        delete floor[i];
    for(int i = 0; i < iCharacter.getCountAMateria(); i++)
        slot[i] = iCharacter.slot[i]->clone();
    for(int i = 0; i < iCharacter.getCountFloorAMateria(); i++)
        floor[i] = iCharacter.floor[i]->clone();

    return (*this);
}

ICharacter::ICharacter(std::string name) :
slot_index(0), countAMateria(0), floor_index(0), countFloorAMateria(0), name(name)
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
    if (isFullSlot() == true)
    {
        std::cout << "inventory is full status" << '\n';
        return;
    }

    slot[slot_index] = m;
    slot_index++;
    countAMateria++;
}

void ICharacter::unequip(int idx)
{
    if (slot[idx] == 0)
        return;
    if (isFullFloor() == true)
    {
        std::cout << "floor is full status" << '\n';
        return;
    }

    this->floor[floor_index] = slot[idx];
    slot[idx] = 0;
    std::cout << "unequip " << this->floor[floor_index]->getType() << '\n';
    floor_index++;
    countFloorAMateria++;
}

void ICharacter::use(int idx, ICharacter& target)
{
    if (slot[idx] == 0)
        return;
    slot[idx]->use(target);
}

int ICharacter::getCountAMateria(void) const
{
    return (this->countAMateria);
}

int ICharacter::getCountFloorAMateria(void) const
{
    return (this->countFloorAMateria);
}

bool ICharacter::isFullSlot(void) const
{
    if (countAMateria == MAX_SLOT_SIZE)
        return (true);
    else
        return (false);
}

bool ICharacter::isFullFloor(void) const
{
    if (countFloorAMateria == FLOOR_SIZE)
        return (true);
    else
        return (false);
}
