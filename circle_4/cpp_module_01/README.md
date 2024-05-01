# ex00 :  BraiiiiiiinnnzzzZ

* Turn-in directory : ex00/
* Files to turn in : Makefile, main.cpp, Zombie.{h, hpp}, Zombie.cpp,
newZombie.cpp, randomChump.cpp
* Forbidden functions : None

First, implement a __Zombie__ class. It has a string private attribute name.
>첫 번째로, __Zombie__ 클래스를 구현하세요. 이 클래스는 문자열 타입의 private 속성인 name을 가지고 있습니다.

Add a member function void announce( void ); to the Zombie class. Zombies
announce themselves as follows:
>Zombie 클래스에 void announce(void); 멤버 함수를 추가하세요. 좀비는 다음과 같이 자신을 소개합니다:
* \<name\>: BraiiiiiiinnnzzzZ...

Don’t print the angle brackets (< and >). For a zombie named Foo, the message
would be:
>꺽쇠 괄호(<와 >)를 출력하지 마세요. 이름이 Foo인 좀비의 메시지는 다음과 같습니다:
* Foo: BraiiiiiiinnnzzzZ...

Then, implement the two following functions:
>그럼, 다음 두 함수를 구현하겠습니다:

* Zombie* newZombie( std::string name );
* It creates a zombie, name it, and return it so you can use it outside of the function
scope.
  >좀비를 생성하고 이름을 지어서 반환하여 함수의 범위를 벗어난 곳에서 사용할 수 있도록 하는 함수입니다.

* void randomChump( std::string name );
* It creates a zombie, name it, and the zombie announces itself.
  >좀비를 생성하고 이름을 지어서 그 좀비가 자신을 소개하도록 하는 함수입니다.

Now, what is the actual point of the exercise? You have to determine in what case
it’s better to allocate the zombies on the stack or heap.
>이 연습의 실제 목적은 무엇인가요? 언제 스택 또는 힙에 좀비를 할당하는 것이 더 나은지를 결정해야 합니다.

Zombies must be destroyed when you don’t need them anymore. The destructor must
print a message with the name of the zombie for debugging purposes.
>좀비는 더 이상 필요하지 않을 때 파괴되어야 합니다. 디버깅을 위해 소멸자는 좀비의 이름과 함께 메시지를 출력해야 합니다.

# ex01 : Moar brainz!
* Turn-in directory : ex01/
* Files to turn in : Makefile, main.cpp, Zombie.{h, hpp}, Zombie.cpp,
zombieHorde.cpp
* Forbidden functions : None

Time to create a __horde of Zombies!__
>좀비 무리를 만들 시간입니다!

Implement the following function in the appropriate file:
>해당 파일에 다음 함수를 구현하세요:
* Zombie* zombieHorde( int N, std::string name );

It must allocate N Zombie objects in a single allocation. Then, it has to initialize the
zombies, giving each one of them the name passed as parameter. The function returns a
pointer to the first zombie.
>이 함수는 단일 할당으로 N개의 좀비 객체를 할당해야 합니다. 그런 다음, 좀비를 초기화하여 각각에게 매개 변수로 전달된 이름을 지정해야 합니다. 함수는 첫 번째 좀비를 가리키는 포인터를 반환해야 합니다.

Implement your own tests to ensure your zombieHorde() function works as expected.
Try to call announce() for each one of the zombies.
>기대한 대로 동작하는지 확인하기 위해 자체 테스트를 구현해보세요. 각 좀비에 대해 announce()를 호출해보세요.

Don’t forget to delete all the zombies and check for __memory leaks.__
>모든 좀비를 삭제하고 메모리 누수를 확인하는 것을 잊지 마세요.

# ex02 : : HI THIS IS BRAIN
* Turn-in directory : ex02/
* Files to turn in : Makefile, main.cpp
* Forbidden functions : None

Write a program that contains:
>포함된 프로그램을 작성해보겠습니다:
* A string variable initialized to "HI THIS IS BRAIN".
  >"HI THIS IS BRAIN"으로 초기화된 문자열 변수가 포함된 프로그램입니다.
* stringPTR: A pointer to the string.
  >stringPTR: 문자열을 가리키는 포인터입니다.
* stringREF: A reference to the string.
  >stringREF: 문자열에 대한 참조입니다.
Your program has to print:
>프로그램은 다음을 출력해야 합니다:
* The memory address of the string variable.
  >문자열 변수의 메모리 주소.
* The memory address held by stringPTR.
  >stringPTR이 가리키는 메모리 주소.
* The memory address held by stringREF.
  >stringREF가 참조하는 메모리 주소.
And then:
  >그리고 나서:
* The value of the string variable.
  >문자열 변수의 값.
* The value pointed to by stringPTR.
  >stringPTR이 가리키는 값.
* The value pointed to by stringREF.
  >stringREF가 참조하는 값.
That’s all, no tricks. The goal of this exercise is to demystify references which can
seem completely new. Although there are some little differences, this is another syntax
for something you already do: address manipulation.
>다 끝났어요. 별 다른 꼼수는 없어요. 이 연습의 목표는 완전히 새로워 보일 수 있는 참조를 명료화하는 것입니다. 몇 가지 작은 차이는 있지만, 이것은 이미 하고 있는 것인 다른 구문입니다: 주소 조작입니다.

# ex03 : Unnecessary violence
* Turn-in directory : ex03/
* Files to turn in : Makefile, main.cpp, Weapon.{h, hpp}, Weapon.cpp, HumanA.{h,hpp}, HumanA.cpp, HumanB.{h, hpp}, HumanB.cpp
* Forbidden functions : None

Implement a Weapon class that has:
>무기 클래스를 구현하세요. 이 클래스는 다음을 갖추어야 합니다:
* A private attribute type, which is a string.
  >하나의 private 속성 type으로, 이는 문자열입니다.
* A getType() member function that returns a const reference to type.
  >type에 대한 const 참조를 반환하는 getType() 멤버 함수를 추가하세요.
* A setType() member function that sets type using the new one passed as parameter.
  >setType() 멤버 함수를 추가하세요. 이 함수는 매개 변수로 전달된 새로운 값을 사용하여 type을 설정합니다.
Now, create two classes: __HumanA__ and __HumanB.__ They both have a Weapon and a
name. They also have a member function attack() that displays (of course, without the
angle brackets):
  >이제 두 개의 클래스 __HumanA__와 __HumanB__를 생성합니다. 이들은 둘 다 무기와 이름을 갖고 있습니다. 또한 attack()라는 멤버 함수가 있으며 (물론, 꺽쇠 괄호 없이) 다음을 표시합니다:
* \<name\> attacks with their \<weapon type\>
  ><name>은(는) 자신의 <weapon type>으로 공격합니다.
HumanA and HumanB are almost the same except for these two tiny details:
>HumanA와 HumanB는 이 두 가지 아주 작은 차이를 제외하고 거의 동일합니다:
* While HumanA takes the Weapon in its constructor, HumanB doesn’t.
  >HumanA는 생성자에서 무기를 가져오지만, HumanB는 그렇지 않습니다.
* HumanB may __not always__ have a Weapon, whereas HumanA will __always__ be armed.
  >HumanB는 항상 무기를 가지고 있지 않을 수 있지만, HumanA는 항상 무장되어 있습니다.

If your implementation is correct, executing the following code will print an attack
with "crude spiked club" then a second attack with "some other type of club" for both
test cases:
>구현이 올바르다면 다음 코드를 실행하면 두 테스트 케이스 모두에서 "crude spiked club"으로 첫 번째 공격이 출력되고, 두 번째 공격은 "some other type of club"으로 출력될 것입니다.

```
int main()
{
  {
    Weapon club = Weapon("crude spiked club");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
  }
  {
    Weapon club = Weapon("crude spiked club");
    HumanB jim("Jim");
    jim.setWeapon(club);
    jim.attack();
    club.setType("some other type of club");
    jim.attack();
  }
  return 0;
}
```

Don’t forget to check for __memory leaks.__
>메모리 누수를 확인하는 것을 잊지 마세요.

* In which case do you think it would be best to use a pointer to
Weapon? And a reference to Weapon? Why? Think about it before
starting this exercise.
>무기에 대한 포인터를 사용하는 경우와 무기에 대한 참조를 사용하는 경우에는 각각 언제가 가장 좋을지 생각해보세요. 왜 그럴까요? 이 연습을 시작하기 전에 고민해 보세요.

# ex04 :  Sed is for losers
* Turn-in directory : ex04/
* Files to turn in : Makefile, main.cpp, *.cpp, *.{h, hpp}
* Forbidden functions : std::string::replace

Create a program that takes three parameters in the following order: a filename and
two strings, s1 and s2.
>다음 순서로 세 개의 매개변수를 사용하는 프로그램을 작성하세요: 파일 이름과 두 개의 문자열 s1 및 s2입니다.

It will open the file <filename> and copies its content into a new file
\<filename\>.replace, replacing every occurrence of s1 with s2.
>그것은 파일 <filename>을 열고 그 내용을 새 파일 <filename>.replace에 복사합니다. 이때 s1의 모든 발생을 s2로 대체합니다.

Using C file manipulation functions is forbidden and will be considered cheating. All
the member functions of the class std::string are allowed, except replace. Use them
wisely!
>C 파일 조작 함수를 사용하는 것은 금지되어 있으며, 부정 행위로 간주될 것입니다. std::string 클래스의 모든 멤버 함수는 허용되지만 replace는 허용되지 않습니다. 현명하게 사용하세요!

Of course, handle unexpected inputs and errors. You have to create and turn in your
own tests to ensure your program works as expected.
>물론, 예상치 못한 입력 및 오류를 처리하세요. 프로그램이 예상대로 작동하는지 확인하기 위해 자체 테스트를 작성하고 제출해야 합니다.

# ex05 : Harl 2.0
* Turn-in directory : ex05/
* Files to turn in : Makefile, main.cpp, Harl.{h, hpp}, Harl.cpp
* Forbidden functions : None

Do you know Harl? We all do, do we? In case you don’t, find below the kind of
comments Harl makes. They are classified by levels:
>네, 나도 Harl의 코멘트를 잘 알고 있어요. 그것들은 상당히 독특해요! Harl은 자신의 코멘트를 서로 다른 레벨로 분류합니다:

* "DEBUG" level: Debug messages contain contextual information. They are mostly
used for problem diagnosis.
>"DEBUG" 레벨: 디버그 메시지에는 문맥 정보가 포함됩니다. 주로 문제 진단에 사용됩니다.
Example: "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
>예시: "나는 7XL 더블 치즈 트리플 피클 특별 케첩 버거에 추가 베이컨을 갖는 것을 정말 좋아해요. 정말로요!"
* "INFO" level: These messages contain extensive information. They are helpful for tracing program execution in a production environment.
  >"INFO" 레벨: 이러한 메시지에는 상세한 정보가 포함됩니다. 제품 환경에서 프로그램 실행을 추적하는 데 도움이 됩니다.
Example: "I cannot believe adding extra bacon costs more money. You didn’t put
enough bacon in my burger! If you did, I wouldn’t be asking for more!"
  >예시: "추가 베이컨을 넣는 데 더 많은 돈이 든다니 믿을 수가 없어요. 내 버거에 충분한 양의 베이컨을 넣지 않았어요! 만약 넣었다면, 더 달라고 하지 않았을 거예요!"
* "WARNING" level: Warning messages indicate a potential issue in the system.
However, it can be handled or ignored.
>"WARNING" 레벨: 경고 메시지는 시스템에서 잠재적인 문제를 나타냅니다. 그러나 이는 처리하거나 무시할 수 있습니다.
Example: "I think I deserve to have some extra bacon for free. I’ve been coming for
years whereas you started working here since last month."
>예시: "나는 몇 년 동안 여기 왔는데, 너는 지난 달부터 여기 일하기 시작했으니 나에게 무료로 추가 베이컨을 제공받을 자격이 있다고 생각해요."
* "ERROR" level: These messages indicate an unrecoverable error has occurred.
This is usually a critical issue that requires manual intervention.
>"ERROR" 레벨: 이러한 메시지는 복구할 수 없는 오류가 발생했음을 나타냅니다. 일반적으로 수동 개입이 필요한 심각한 문제입니다.
Example: "This is unacceptable! I want to speak to the manager now."
>예시: "이건 용납할 수 없어요! 지금 당장 매니저와 이야기하고 싶어요."

You are going to automate Harl. It won’t be difficult since it always says the same
things. You have to create a __Harl__ class with the following private member functions:
>당신은 Harl을 자동화할 것입니다. 항상 같은 말만 하기 때문에 어렵지 않을 것입니다. 다음과 같은 private 멤버 함수를 갖는 __Harl__ 클래스를 만들어야 합니다:
* void debug( void );
* void info( void );
* void warning( void );
* void error( void );

__Harl__ also has a public member function that calls the four member functions above
depending on the level passed as parameter:
>__Harl__은 또한 매개변수로 전달된 레벨에 따라 위의 네 멤버 함수를 호출하는 공개 멤버 함수도 갖습니다:
* void complain( std::string level );

The goal of this exercise is to use pointers to member functions. This is not a
suggestion. Harl has to complain without using a forest of if/else if/else. It doesn’t think
twice!
>이 연습의 목표는 멤버 함수에 대한 포인터를 사용하는 것입니다. 이것은 제안이 아닙니다. Harl은 if/else if/else의 숲을 사용하지 않고도 불평을 해야 합니다. 그는 한 번도 생각하지 않아요!

Create and turn in tests to show that Harl complains a lot. You can use the examples
of comments listed above in the subject or choose to use comments of your own.
>"Harl이 자주 불평하는 것을 보여주는 시험지를 만들어서 제출하세요. 주제로 나열된 댓글 예시를 사용하거나 직접 댓글을 만드셔도 됩니다."

# ex06 :  Harl filter
* Turn-in directory : ex06/
* Files to turn in : Makefile, main.cpp, Harl.{h, hpp}, Harl.cpp
* Forbidden functions : None

Sometimes you don’t want to pay attention to everything Harl says. Implement a
system to filter what Harl says depending on the log levels you want to listen to.
>가끔은 Harl이 하는 말에 모두 관심을 기울이고 싶지 않을 때도 있습니다. 듣고 싶은 로그 레벨에 따라 Harl의 말을 필터링하는 시스템을 구현하세요.

Create a program that takes as parameter one of the four levels. It will display all
messages from this level and above. For example:
>프로그램을 만들어서 네 가지 레벨 중 하나를 매개변수로 받습니다. 이 프로그램은 해당 레벨 및 그 이상의 모든 메시지를 표시합니다. 예를 들어:

```
$> ./harlFilter "WARNING"
[ WARNING ]
I think I deserve to have some extra bacon for free.
I've been coming for years whereas you started working here since last month.
[ ERROR ]
This is unacceptable, I want to speak to the manager now.
$> ./harlFilter "I am not sure how tired I am today..."
[ Probably complaining about insignificant problems ]
```

Although there are several ways to deal with Harl, one of the most effective is to
SWITCH it off.
>Harl과 대응하는 여러 방법이 있지만 가장 효과적인 하나는 그것을 끄는 것입니다.

Give the name harlFilter to your executable.
>프로그램을 "harlFilter"라고 지정하겠습니다.

You must use, and maybe discover, the switch statement in this exercise.
>이 연습에서 스위치 문을 사용할 것입니다. 가능한 새로운 것을 발견할지도 모르겠네요!

You can pass this module without doing exercise 06.
>이 모듈은 연습 06을 건너뛰고 진행할 수 있습니다.
