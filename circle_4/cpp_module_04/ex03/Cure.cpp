#include "Cure.hpp"

Cure::Cure(void) : AMateria::AMateria("cure")
{
    std::cout << "this is Cure constructor" << '\n';
}

Cure::~Cure(void)
{
    std::cout << "this is Cure desstructor" << '\n';
}
        
Cure::Cure(const Cure& cure)
{
    *this = cure;
}

Cure& Cure::operator=(const Cure& cure)
{
    if (&cure == this)
        return (*this);

    return (*this);
}

Cure::Cure(std::string const & type)
{
}


AMateria* Cure::clone() const
{
    Cure *c = new Cure();
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals" << target.getName() << "'s wounds *" << '\n';
}
