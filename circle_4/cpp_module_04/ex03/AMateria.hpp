#ifndef _AMATERIA
# define _AMATERIA

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class AMateria
{
    public:
        /*canonical form*/
        AMateria(void);
        virtual ~AMateria(void);
        AMateria(const AMateria& amateria);
        AMateria& operator=(const AMateria& amateria);

        AMateria(std::string const & type);
        std::string const & getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);

    protected:
        std::string type;
};

#endif
