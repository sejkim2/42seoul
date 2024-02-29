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