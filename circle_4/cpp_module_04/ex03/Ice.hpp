#ifndef _ICE
# define _ICE

# include "AMateria.hpp"

class Ice
{
    public:
        /*canonical form*/
        Ice(void);
        virtual ~Ice(void);
        Ice(const Ice& ice);
        Ice& operator=(const Ice& ice);

        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};

#endif
