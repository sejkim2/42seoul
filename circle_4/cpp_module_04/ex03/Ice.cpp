#include "Ice.hpp"

Ice::Ice(void)
{
    std::cout << "this is Ice constructor" << '\n';
}

Ice::~Ice(void)
{
    std::cout << "this is Ice desstructor" << '\n';
}
        
Ice::Ice(const Ice& ice)
{
    *this = ice;
}

Ice& Ice::operator=(const Ice& ice)
{
    if (&ice == this)
        return (*this);
    return (*this);
}

AMateria* AMateria::clone() const
{
}

void AMateria::use(ICharacter& target)
{

}
