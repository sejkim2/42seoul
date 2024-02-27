#ifndef _FIXED
# define _FIXED

# include <iostream>

class Fixed
{
    public:
        Fixed(void);
        ~Fixed(void);
        Fixed(const Fixed& fixed);
        Fixed& operator=(const Fixed& fixed);
        int getRawBits(void) const;
        void setRawBits(int const raw);
    private:
        int rawBits;
        const static int fractionalBits = 8;
};

#endif