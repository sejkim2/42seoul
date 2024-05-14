#ifndef _ANIMAL
# define _ANIMAL

# include <iostream>
# include <string>
# include "Brain.hpp"

class Animal
{
    public:
        /*canonical form*/
        Animal(void);
        virtual ~Animal(void);
        Animal(const Animal& animal);
        virtual Animal& operator=(const Animal& animal);

        virtual std::string getType(void) const;
        virtual void makeSound(void) const;

    protected:
        Animal(std::string type);   //call in child contructor
        std::string type;
};

#endif
