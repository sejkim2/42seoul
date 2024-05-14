#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
    std::cout << "this is WrongCat constructor" << '\n';
}

WrongCat::~WrongCat(void)
{
    std::cout << "this is WrongCat destructor" << '\n';
}
        
WrongCat::WrongCat(const WrongCat& wrongCat) : WrongAnimal(wrongCat)
{
    *this = wrongCat;
}

WrongCat& WrongCat::operator=(const WrongCat& wrongCat)
{
    if (&wrongCat == this)
        return (*this);

    WrongAnimal::operator=(wrongCat);
    
    return (*this);
}

std::string WrongCat::getType(void) const
{
    return (WrongAnimal::getType());
}

void WrongCat::makeSound(void) const
{
    std::cout << "WrongCat's sound : Yaong" << '\n';
}
