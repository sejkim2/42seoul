# ex00 : Polymorphism
* Turn-in directory : ex00/
* Files to turn in : Makefile, main.cpp, *.cpp, *.{h, hpp}
* Forbidden functions : None

For every exercise, you have to provide the most complete tests you can.
Constructors and destructors of each class must display specific messages. Don’t use the same message for all classes.
>모든 운동에 대해 가장 완전한 테스트를 제공해야 합니다. 각 클래스의 생성자와 소멸자는 특정 메시지를 표시해야 합니다. 모든 클래스에 동일한 메시지를 사용하지 마세요.

Start by implementing a simple base class called Animal. It has one protected attribute:
>간단한 기본 클래스인 Animal을 구현하여 시작하십시오. 이 클래스에는 하나의 보호된 속성이 있습니다.

* std::string type;

Implement a Dog class that inherits from Animal.
>Dog 클래스를 Animal로부터 상속하는 것을 구현해주세요.

Implement a Cat class that inherits from Animal.
>Animal 클래스를 상속하는 Cat 클래스를 구현해주세요.

These two derived classes must set their type field depending on their name. Then,
the Dog’s type will be initialized to "Dog", and the Cat’s type will be initialized to "Cat".
The type of the Animal class can be left empty or set to the value of your choice.
>이 두 파생 클래스는 이름에 따라 자신의 타입 필드를 설정해야 합니다. 그래서, Dog의 타입은 "Dog"로 초기화되고, Cat의 타입은 "Cat"로 초기화됩니다. Animal 클래스의 타입은 비워둘 수도 있고, 원하는 값으로 설정할 수 있습니다.

Every animal must be able to use the member function : makeSound()
>모든 동물은 makeSound() 멤버 함수를 사용할 수 있어야 합니다.

It will print an appropriate sound (cats don’t bark).
>makeSound() 함수는 적절한 소리를 출력해야 합니다 (고양이는 짖지 않습니다).

Running this code should print the specific sounds of the Dog and Cat classes, not the Animal’s.
>해당 코드를 실행하면 Dog 및 Cat 클래스의 특정 소리가 출력되어야 하며, Animal의 소리가 아니어야 합니다.

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
>작동 방식을 이해했는지 확인하기 위해 WrongAnimal 클래스를 상속하는 WrongCat 클래스를 구현하십시오. 위의 코드에서 Animal과 Cat을 잘못된 것으로 바꾸면 WrongCat은 WrongAnimal 소리를 출력해야 합니다.

Implement and turn in more tests than the ones given above.
>더 많은 테스트를 구현하고 제공해주세요.

# ex01 : I don’t want to set the world on fire
* Turn-in directory : ex01/
* Files to turn in : Files from previous exercise + *.cpp, *.{h, hpp}
* Forbidden functions : None

Constructors and destructors of each class must display specific messages.
>각 클래스의 생성자와 소멸자는 특정 메시지를 표시해야 합니다.

Implement a Brain class. It contains an array of 100 std::string called ideas.
This way, Dog and Cat will have a private Brain* attribute.
Upon construction, Dog and Cat will create their Brain using new Brain();
Upon destruction, Dog and Cat will delete their Brain.
>다음은 Brain 클래스를 구현한 것입니다. 이 클래스에는 ideas라는 100개의 std::string 배열이 있습니다. 이렇게 하면 Dog와 Cat이 Brain* 속성을 가집니다. 생성될 때 Dog와 Cat은 new Brain()을 사용하여 자신의 Brain을 만듭니다. 소멸될 때 Dog와 Cat은 자신의 Brain을 삭제합니다.

In your main function, create and fill an array of Animal objects. Half of it will
be Dog objects and the other half will be Cat objects. At the end of your program
execution, loop over this array and delete every Animal. You must delete directly dogs
and cats as Animals. The appropriate destructors must be called in the expected order.
>메인 함수에서는 Animal 객체 배열을 생성하고, 이 배열을 반으로 채워서 반은 Dog 객체이고 나머지 반은 Cat 객체가 됩니다. 프로그램 실행이 끝나면 이 배열을 순회하면서 모든 Animal을 삭제합니다. 각 객체는 직접 Dog나 Cat으로서가 아니라 Animal로 삭제되어야 합니다. 이때 예상대로 적절한 소멸자가 호출되어야 합니다.

Don’t forget to check for memory leaks
>메모리 누수를 확인하는 것을 잊지 마세요.

A copy of a Dog or a Cat mustn’t be shallow. Thus, you have to test that your copies are deep copies!
>개 또는 고양이의 복사본은 얕은 복사가 되어서는 안됩니다. 따라서 복사본이 깊은 복사인지 테스트해야 합니다!

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
>더 많은 테스트를 구현하고 제출하라

# ex02 : Abstract class
* Turn-in directory : ex02/
* Files to turn in : Files from previous exercise + *.cpp, *.{h, hpp}
* Forbidden functions : None

Creating Animal objects doesn’t make sense after all. It’s true, they make no sound!
>동물 객체를 생성하는 것은 사실 의미가 없습니다. 맞아요, 동물은 소리를 내지 않습니다!

To avoid any possible mistakes, the default Animal class should not be instantiable.
Fix the Animal class so nobody can instantiate it. Everything should work as before.
>모든 실수를 피하기 위해 기본 Animal 클래스는 인스턴스화할 수 없도록 해야 합니다. Animal 클래스를 수정하여 누구도 인스턴스화할 수 없도록 만들어야 합니다. 모든 것이 이전과 같이 작동해야 합니다.

If you want to, you can update the class name by adding a A prefix to Animal.
>만약 원하신다면, Animal 클래스에 A 접두사를 추가하여 클래스 이름을 업데이트할 수 있습니다.

# ex03 : Interface & recap
* Turn-in directory : ex03/
* Files to turn in : Makefile, main.cpp, *.cpp, *.{h, hpp}
* Forbidden functions : None

Interfaces don’t exist in C++98 (not even in C++20). However, pure abstract classes
are commonly called interfaces. Thus, in this last exercise, let’s try to implement interfaces in order to make sure you got this module.
>C++98에서는 인터페이스가 존재하지 않습니다(심지어 C++20에서도 그렇습니다). 그러나 순수 가상 클래스는 일반적으로 인터페이스로 불립니다. 따라서 이 마지막 연습에서는 인터페이스를 구현하여 이 모듈을 이해했는지 확인해 보겠습니다.

Complete the definition of the following AMateria class and implement the necessary member functions.
>다음은 AMateria 클래스의 정의를 완성하고 필요한 멤버 함수를 구현하세요.

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

Implement the Materias concrete classes Ice and Cure. Use their name in lowercase ("ice" for Ice, "cure" for Cure) to set their types. Of course, their member function clone() will return a new instance of the same type (i.e., if you clone an Ice Materia, you will get a new Ice Materia).
>AMateria 클래스의 구체적인 클래스인 Ice와 Cure를 구현하세요. 타입을 설정할 때 소문자로 ("ice"는 Ice에 대해, "cure"는 Cure에 대해) 사용하십시오. 물론, 그들의 멤버 함수 clone()은 동일한 타입의 새로운 인스턴스를 반환합니다 (즉, Ice Materia를 복제하면 새로운 Ice Materia를 얻게 됩니다).

The use(ICharacter&) member function will display:
>use(ICharacter&) 멤버 함수는 다음을 표시합니다.

* Ice: "* shoots an ice bolt at <name> *"
* Cure: "* heals <name>’s wounds *"

\<name> is the name of the Character passed as parameter. Don’t print the angle
brackets (< and >).
>\<name>은 매개 변수로 전달된 Character의 이름입니다. 꺽쇠 괄호 (<와 >)를 출력하지 마세요.

* While assigning a Materia to another, copying the type doesn’t make sense.
  >다른 Materia에 Materia를 할당할 때, 타입을 복사하는 것은 의미가 없습니다.

Write the concrete class Character which will implement the following interface:
>다음 인터페이스를 구현하는 Character 구체 클래스를 작성하겠습니다.

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
>캐릭터는 최대 4개의 슬롯을 가진 인벤토리를 소유하며, 따라서 최대 4개의 마테리아를 보유할 수 있습니다. 인벤토리는 생성 시 비어 있습니다. 캐릭터는 첫 번째 빈 슬롯부터 마테리아를 장착합니다. 이는 슬롯 0부터 슬롯 3까지의 순서대로 이루어집니다. 인벤토리가 가득 찬 상태에서 마테리아를 추가하려고 하거나, 존재하지 않는 마테리아를 사용하거나 장착 해제하려고 할 때는 아무 것도 하지 마십시오 (하지만 여전히 버그는 금지됩니다). unequip() 멤버 함수는 마테리아를 삭제해서는 안됩니다!

* Handle the Materias your character left on the floor as you like. Save the addresses before calling unequip(), or anything else, but don’t forget that you have to avoid memory leaks.
  >캐릭터가 바닥에 놓은 마테리아를 원하는 대로 처리하세요. unequip()을 호출하기 전에 주소를 저장하거나 다른 작업을 수행할 수 있지만, 메모리 누수를 방지해야 합니다.

The use(int, ICharacter&) member function will have to use the Materia at the
slot[idx], and pass the target parameter to the AMateria::use function.
>use(int, ICharacter&) 멤버 함수는 슬롯[idx]의 Materia를 사용해야 하며, 대상 매개 변수를 AMateria::use 함수에 전달해야 합니다.

* Your character’s inventory will be able to support any type of AMateria.
  >캐릭터의 인벤토리는 모든 유형의 AMateria를 지원할 수 있을 것입니다.

Your Character must have a constructor taking its name as a parameter. Any copy
(using copy constructor or copy assignment operator) of a Character must be deep.
During copy, the Materias of a Character must be deleted before the new ones are added
to their inventory. Of course, the Materias must be deleted when a Character is destroyed.
> Character는 이름을 매개 변수로 받는 생성자를 가져야 합니다. Character의 복사본(복사 생성자 또는 복사 할당 연산자를 사용하여)은 모두 깊은 복사여야 합니다. 복사 중에 Character의 Materias는 새로운 Materias가 인벤토리에 추가되기 전에 삭제되어야 합니다. 물론, Character가 소멸될 때 Materias는 삭제되어야 합니다.

Write the concrete class MateriaSource which will implement the following interface:
>다음 인터페이스를 구현하는 MateriaSource의 구체 클래스를 작성하겠습니다.

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
  >> 매개 변수로 전달된 Materia를 복사하여 나중에 복제할 수 있도록 메모리에 저장합니다. 캐릭터와 마찬가지로 MateriaSource는 최대 4개의 Materias를 알 수 있습니다. 이들은 반드시 고유하지 않아도 됩니다.

* createMateria(std::string const &)
  > Returns a new Materia. The latter is a copy of the Materia previously learned by
the MateriaSource whose type equals the one passed as parameter. Returns 0 if
the type is unknown.
  >> 이전에 MateriaSource가 학습한 Materia의 복사본을 반환합니다. 이전에 학습한 Materia의 유형이 매개 변수로 전달된 유형과 동일한 경우 해당 복사본을 반환합니다. 유형이 알려지지 않은 경우 0을 반환합니다.

In a nutshell, your MateriaSource must be able to learn "templates" of Materias to
create them when needed. Then, you will be able to generate a new Materia using just
a string that identifies its type.
>간단히 말해, MateriaSource는 필요할 때 Materias의 "템플릿"을 학습하여 생성할 수 있어야 합니다. 그런 다음, 단순히 유형을 식별하는 문자열을 사용하여 새로운 Materia를 생성할 수 있어야 합니다.

Running this code:
>아래 코드를 실행하세요:

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
>나와야 하는 결과:

```bash
$> clang++ -W -Wall -Werror *.cpp
$> ./a.out | cat -e
* shoots an ice bolt at bob *$
* heals bob's wounds *$
```

As usual, implement and turn in more tests than the ones given above.
>평소처럼, 주어진 것보다 더 많은 테스트를 구현하고 제출하십시오.

You can pass this module without doing exercise 03.
>이 모듈을 수료하기 위해선 Exercise 03을 수행하지 않아도 됩니다.

* Turn in your assignment in your Git repository as usual. Only the work inside your
repository will be evaluated during the defense. Don’t hesitate to double check the
names of your folders and files to ensure they are correct.
>과제를 보통대로 깃 저장소에 제출하십시오. 심사 중에는 귀하의 저장소 내의 작업만 평가됩니다. 폴더와 파일 이름이 올바른지 다시 한번 확인하시기 바랍니다.





