# ex00 : Polymorphism
* Turn-in directory : ex00/
* Files to turn in : Makefile, main.cpp, *.cpp, *.{h, hpp}
* Forbidden functions : None

For every exercise, you have to provide the most complete tests you can.
Constructors and destructors of each class must display specific messages. Don’t use the same message for all classes.
>

Start by implementing a simple base class called Animal. It has one protected
attribute:
>

* std::string type;

Implement a Dog class that inherits from Animal.
>

Implement a Cat class that inherits from Animal.
>

These two derived classes must set their type field depending on their name. Then,
the Dog’s type will be initialized to "Dog", and the Cat’s type will be initialized to "Cat".
The type of the Animal class can be left empty or set to the value of your choice.
>

Every animal must be able to use the member function : makeSound()
>

It will print an appropriate sound (cats don’t bark).
>

Running this code should print the specific sounds of the Dog and Cat classes, not
the Animal’s.
>

```c++
int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();
...
return 0;
}
```

To ensure you understood how it works, implement a WrongCat class that inherits
from a WrongAnimal class. If you replace the Animal and the Cat by the wrong ones
in the code above, the WrongCat should output the WrongAnimal sound.
>

Implement and turn in more tests than the ones given above.
>

# ex01 : I don’t want to set the world on fire
* Turn-in directory : ex01/
* Files to turn in : Files from previous exercise + *.cpp, *.{h, hpp}
* Forbidden functions : None

Constructors and destructors of each class must display specific messages.
>

Implement a Brain class. It contains an array of 100 std::string called ideas.
This way, Dog and Cat will have a private Brain* attribute.
Upon construction, Dog and Cat will create their Brain using new Brain();
Upon destruction, Dog and Cat will delete their Brain.
>

In your main function, create and fill an array of Animal objects. Half of it will
be Dog objects and the other half will be Cat objects. At the end of your program
execution, loop over this array and delete every Animal. You must delete directly dogs
and cats as Animals. The appropriate destructors must be called in the expected order.
>

Don’t forget to check for memory leaks
>

A copy of a Dog or a Cat mustn’t be shallow. Thus, you have to test that your copies
are deep copies!
>

```c++
int main()
{
const Animal* j = new Dog();
const Animal* i = new Cat();
delete j;//should not create a leak
delete i;
...
return 0;
}
```

Implement and turn in more tests than the ones given above.
>

# ex02 : Abstract class
* Turn-in directory : ex02/
* Files to turn in : Files from previous exercise + *.cpp, *.{h, hpp}
* Forbidden functions : None

Creating Animal objects doesn’t make sense after all. It’s true, they make no sound!
>

To avoid any possible mistakes, the default Animal class should not be instantiable.
Fix the Animal class so nobody can instantiate it. Everything should work as before.
>

If you want to, you can update the class name by adding a A prefix to Animal.
>

# ex03 : Interface & recap
* Turn-in directory : ex03/
* Files to turn in : Makefile, main.cpp, *.cpp, *.{h, hpp}
* Forbidden functions : None

Interfaces don’t exist in C++98 (not even in C++20). However, pure abstract classes
are commonly called interfaces. Thus, in this last exercise, let’s try to implement interfaces in order to make sure you got this module.
>

Complete the definition of the following AMateria class and implement the necessary
member functions.
>

```c++
class AMateria
{
protected:
[...]
public:
AMateria(std::string const & type);
[...]
std::string const & getType() const; //Returns the materia type
virtual AMateria* clone() const = 0;
virtual void use(ICharacter& target);
};
```

Implement the Materias concrete classes Ice and Cure. Use their name in lowercase ("ice" for Ice, "cure" for Cure) to set their types. Of course, their member function
clone() will return a new instance of the same type (i.e., if you clone an Ice Materia,
you will get a new Ice Materia).
>

The use(ICharacter&) member function will display:
>

* Ice: "* shoots an ice bolt at <name> *"
* Cure: "* heals <name>’s wounds *"

\<name> is the name of the Character passed as parameter. Don’t print the angle
brackets (< and >).
>

* While assigning a Materia to another, copying the type doesn’t make sense.
  >

Write the concrete class Character which will implement the following interface:
>

```c++
class ICharacter
{
public:
virtual ~ICharacter() {}
virtual std::string const & getName() const = 0;
virtual void equip(AMateria* m) = 0;
virtual void unequip(int idx) = 0;
virtual void use(int idx, ICharacter& target) = 0;
};
```

The Character possesses an inventory of 4 slots, which means 4 Materias at most.
The inventory is empty at construction. They equip the Materias in the first empty slot
they find. This means, in this order: from slot 0 to slot 3. In case they try to add
a Materia to a full inventory, or use/unequip an unexisting Materia, don’t do anything
(but still, bugs are forbidden). The unequip() member function must NOT delete the
Materia!
>

* Handle the Materias your character left on the floor as you like. Save the addresses before calling unequip(), or anything else, but don’t forget that you have to avoid memory leaks.
  >

The use(int, ICharacter&) member function will have to use the Materia at the
slot[idx], and pass the target parameter to the AMateria::use function.
>

* Your character’s inventory will be able to support any type of AMateria.
  >

Your Character must have a constructor taking its name as a parameter. Any copy
(using copy constructor or copy assignment operator) of a Character must be deep.
During copy, the Materias of a Character must be deleted before the new ones are added
to their inventory. Of course, the Materias must be deleted when a Character is destroyed.
> fad

Write the concrete class MateriaSource which will implement the following interface:
>

```c++
class IMateriaSource
{
public:
virtual ~IMateriaSource() {}
virtual void learnMateria(AMateria*) = 0;
virtual AMateria* createMateria(std::string const & type) = 0;
};
```

* learnMateria(AMateria*)
  > Copies the Materia passed as a parameter and store it in memory so it can be cloned later. Like the Character, the MateriaSource can know at most 4 Materias. They are not necessarily unique.
  >> fd

* createMateria(std::string const &)
  > Returns a new Materia. The latter is a copy of the Materia previously learned by
the MateriaSource whose type equals the one passed as parameter. Returns 0 if
the type is unknown.
  >> 

In a nutshell, your MateriaSource must be able to learn "templates" of Materias to
create them when needed. Then, you will be able to generate a new Materia using just
a string that identifies its type.
>

Running this code:
>

```c++
int main()
{
IMateriaSource* src = new MateriaSource();
src->learnMateria(new Ice());
src->learnMateria(new Cure());
ICharacter* me = new Character("me");
AMateria* tmp;
tmp = src->createMateria("ice");
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);
ICharacter* bob = new Character("bob");
me->use(0, *bob);
me->use(1, *bob);
delete bob;
delete me;
delete src;
return 0;
}
```

Should output:
>

```bash
$> clang++ -W -Wall -Werror *.cpp
$> ./a.out | cat -e
* shoots an ice bolt at bob *$
* heals bob's wounds *$
```

As usual, implement and turn in more tests than the ones given above.
>

You can pass this module without doing exercise 03.
>

* Turn in your assignment in your Git repository as usual. Only the work inside your
repository will be evaluated during the defense. Don’t hesitate to double check the
names of your folders and files to ensure they are correct.
>





