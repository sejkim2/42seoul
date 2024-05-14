#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

void leaks()
{
    system("leaks ex01");
}

int main()
{
    atexit(leaks);
    
    {
        std::cout << "_____________________________test case 1_____________________________" << '\n';
        
        const Animal *j = new Dog();
        const Animal *i = new Cat();
        delete j; // should not create a leak
        delete i;
    }
    {
        std::cout << "_____________________________test case 2_____________________________" << '\n';
        
        Animal *animals[6];
        for(int i = 0; i<3; i++)
            animals[i] = new Dog();
        for(int i = 3; i < 6; i++)
            animals[i] = new Cat();

        for(int i = 0; i<6; i++)
            delete animals[i];
    }
    {
        std::cout << "_____________________________test case 3_____________________________" << '\n';
        Animal *p = new Dog();
        Animal *p2 = new Dog();
        *p = *p2;
        delete p;
        delete p2;
    }
    {
        std::cout << "_____________________________test case 3_____________________________" << '\n';
        // Animal *p = new Animal();
    }
}