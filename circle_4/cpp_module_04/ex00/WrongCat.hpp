#ifndef _WRONG_CAT
# define _WRONG_CAT

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        /*canonical form*/
        WrongCat(void);
        virtual ~WrongCat(void);
        WrongCat(const WrongCat& wrongCat);
        WrongCat& operator=(const WrongCat& wrongCat);

        virtual std::string getType(void) const;
        void makeSound(void) const;
};

#endif