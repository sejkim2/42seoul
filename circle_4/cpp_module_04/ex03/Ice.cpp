#include "Ice.hpp"

Ice::Ice(void) : AMateria::AMateria("ice")
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

Ice::Ice(std::string const & type)
{
}


AMateria* Ice::clone() const
{
    Ice *c = new Ice();
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << '\n';
}
