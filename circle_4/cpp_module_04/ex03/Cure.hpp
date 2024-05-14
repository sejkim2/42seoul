#ifndef _CURE
# define _CURE

# include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        /*canonical form*/
        Cure(void);
        virtual ~Cure(void);
        Cure(const Cure& cure);
        Cure& operator=(const Cure& cure);

        Cure(std::string const & type);
        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};

#endif
