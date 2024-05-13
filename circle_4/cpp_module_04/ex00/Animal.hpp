#ifndef _ANIMAL
# define _ANIMAL

# include <iostream>
# include <string>

class Animal
{
    public:
        /*canonical form*/
        Animal(void);
        virtual ~Animal(void);
        Animal(const Animal& animal);
        Animal& operator=(const Animal& animal);

        virtual std::string getType(void) const;        //virtual function
        // void        setType(std::string type);
        virtual void makeSound(void) const;

    protected:
        Animal(std::string type);   //call in child contructor
        std::string type;
};

#endif
