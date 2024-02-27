#include "Fixed.hpp"

Fixed::Fixed(void) : rawBits(0)
{
    std::cout << "Default constructor called" << '\n';
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << '\n';
}

// Fixed::Fixed(const Fixed& fixed) : rawBits(fixed.getRawBits())
// {
//     std::cout << "Copy constructor called" << '\n';
//     // rawBits = fixed.getRawBits();
// }

Fixed::Fixed(const Fixed& fixed)
{
    std::cout << "Copy constructor called" << '\n';
    *this = fixed;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
    std::cout << "Assignation operator called" << '\n';
    if (&fixed == this)
        return (*this);
    rawBits = fixed.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << '\n';
    return (rawBits);
}

void Fixed::setRawBits(int const raw)
{
    this->rawBits = raw;
}
