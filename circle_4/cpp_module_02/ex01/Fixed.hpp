#ifndef _FIXED
# define _FIXED

# include <iostream>

class Fixed
{
    public:
        /*canonical form*/
        Fixed(void);
        ~Fixed(void);
        Fixed(const Fixed& fixed);
        Fixed& operator=(const Fixed& fixed);

        Fixed(const int n);
        /*getter and setter*/
        int getRawBits(void) const;
        void setRawBits(int const raw);
    private:
        int rawBits;
        const static int fractionalBits = 8;
};

#endif