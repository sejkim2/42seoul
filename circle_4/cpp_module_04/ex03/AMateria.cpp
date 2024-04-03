#include "AMateria.hpp"

AMateria::AMateria(void)
{
    std::cout << "this is AMateria constructor" << '\n';
}

AMateria::~AMateria(void)
{
    std::cout << "this is AMateria desstructor" << '\n';
}
        
AMateria::AMateria(const AMateria& amateria)
{
    *this = amateria;
}

AMateria& AMateria::operator=(const AMateria& amateria)
{
    if (&amateria == this)
        return (*this);
    return (*this);
}

AMateria::AMateria(std::string const & type) : type(type)
{
}

std::string const & AMateria::getType() const
{
    return (type);
}