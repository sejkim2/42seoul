#ifndef _AMATERIA
# define _AMATERIA

# include <iostream>
# include <string>

class AMateria
{
    public:
        /*canonical form*/
        AMateria(void);
        virtual ~AMateria(void);
        AMateria(const AMateria& amateria);
        AMateria& operator=(const AMateria& amateria);
};

#endif