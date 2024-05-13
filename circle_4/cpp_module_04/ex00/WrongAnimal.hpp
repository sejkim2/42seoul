#ifndef _WRONG_ANIMAL
# define _WRONG_ANIMAL

# include <iostream>
# include <string>

class WrongAnimal
{
    public:
        /*canonical form*/
        WrongAnimal(void);
        virtual ~WrongAnimal(void);
        WrongAnimal(const WrongAnimal& wrongAnimal);
        WrongAnimal& operator=(const WrongAnimal& wrongAnimal);

        virtual std::string getType(void) const;        //virtual function
        void makeSound(void) const;

    protected:
        WrongAnimal(std::string type);   //call in child contructor
        std::string type;
};

#endif
