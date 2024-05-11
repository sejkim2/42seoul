#ifndef _FIXED
# define _FIXED

# include <iostream>
# include <cmath>

class Fixed
{
    public:
        /*canonical form*/
        Fixed(void);
        ~Fixed(void);
        Fixed(const Fixed& fixed);
        Fixed& operator=(const Fixed& fixed);

        Fixed(const int n);
        Fixed(const float f);
        
        bool operator>(const Fixed& fixed) const;
        bool operator<(const Fixed& fixed) const;
        bool operator>=(const Fixed& fixed) const;
        bool operator<=(const Fixed& fixed) const;
        bool operator==(const Fixed& fixed) const;
        bool operator!=(const Fixed& fixed) const;

        Fixed operator+(const Fixed& fixed) const;
        Fixed operator-(const Fixed& fixed) const;
        Fixed operator*(const Fixed& fixed) const;
        Fixed operator/(const Fixed& fixed) const;

        const Fixed&   operator++(void);
        Fixed   operator++(int);
        const Fixed& operator--(void);
        Fixed operator--(int); 

        static Fixed& min(Fixed &a, Fixed &b);
        static const Fixed& min(const Fixed &a, const Fixed &b);
        static Fixed& max(Fixed &a, Fixed &b);
        static const Fixed& max(const Fixed &a, const Fixed &b);

        /*getter and setter*/
        int getRawBits(void) const;
        void setRawBits(int const raw);

        float toFloat(void) const;
        int toInt(void) const;
    private:
        int rawBits;
        const static int fractionalBits = 8;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif