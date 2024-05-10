#include "Fixed.hpp"

Fixed::Fixed(void) : rawBits(0)
{
    std::cout << "Default constructor called" << '\n';
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << '\n';
}

Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called" << '\n';
    rawBits = n * (1 << fractionalBits);
}

Fixed::Fixed(const float f)
{
    std::cout << "Float constructor called" << '\n';
    rawBits = roundf(f * (1 << fractionalBits));
}

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

bool Fixed::operator>(const Fixed& fixed)
{
    return (this->getRawBits() > fixed.getRawBits());
}

bool Fixed::operator<(const Fixed& fixed)
{
    return (this->getRawBits() < fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed& fixed)
{
    return (this->getRawBits() >= fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed& fixed)
{
    return (this->getRawBits() <= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed& fixed)
{
    return (this->getRawBits() == fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed& fixed)
{
    return (this->getRawBits() != fixed.getRawBits());
}

Fixed Fixed::operator+(const Fixed& fixed)
{
    return (this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed& fixed)
{
    return (this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed& fixed)
{
    return (this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed& fixed)
{
    return (this->toFloat() / fixed.toFloat());
}

Fixed&   Fixed::operator++(void)
{
    ++this->rawBits;
    return (*this);
}

Fixed   Fixed::operator++(int) 
{
    Fixed tmp(*this);
    tmp.rawBits = this->rawBits++;
    return (tmp);
}

Fixed& Fixed::operator--(void)
{
    --this->rawBits;
    return (*this);
}

Fixed Fixed::operator--(int) 
{
    Fixed tmp(*this);
    tmp.rawBits = this->rawBits--;
    return (tmp);
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

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}

float Fixed::toFloat(void) const
{
    return ((float)rawBits / (1 << fractionalBits));
}

int Fixed::toInt(void) const
{
    return (rawBits / (1 << fractionalBits));
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return (out);
}