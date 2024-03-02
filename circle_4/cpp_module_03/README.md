# ex00
First, you have to implement a class! How original!
>먼저 클래스를 구현해야 합니다! 얼마나 독창적인가요!

It will be called ClapTrap and will have the following private attributes initialized
to the values specified in brackets:
>이것은 ClapTrap이라고 불리며, 다음과 같은 개인 속성이 괄호 안에 지정된 값으로 초기화됩니다:

* Name, which is passed as parameter to a constructor
  >이름은 생성자에 전달되는 매개변수로 지정됩니다.
* Hit points (10), represent the health of the ClapTrap
  >히트 포인트(10)은 ClapTrap의 체력을 나타냅니다.
* Energy points (10)
  >에너지 포인트(10)
* Attack damage (0)
  >공격 데미지(0)

Add the following public member functions so the ClapTrap looks more realistic:
>다음과 같은 공개 멤버 함수를 추가하여 ClapTrap이 더 현실적으로 보이도록 합니다:

* void attack(const std::string& target);
* void takeDamage(unsigned int amount);
* void beRepaired(unsigned int amount);

When ClapTrack attacks, it causes its target to lose \<attack damage> hit points.
When ClapTrap repairs itself, it gets \<amount> hit points back. Attacking and repairing
cost 1 energy point each. Of course, ClapTrap can’t do anything if it has no hit points
or energy points left.
>ClapTrap이 공격할 때 대상은 \<attack damage>의 히트 포인트를 잃게 됩니다. ClapTrap이 자가 수리할 때, \<amount>의 히트 포인트를 회복합니다. 공격과 수리는 각각 1 에너지 포인트를 소모합니다. 물론, ClapTrap이 히트 포인트나 에너지 포인트가 모두 소진되었다면 아무 것도 할 수 없습니다.

In all of these member functions, you have to print a message to describe what happens. For example, the attack() function may display something like (of course, without
the angle brackets):
>모든 멤버 함수에서 발생하는 내용을 설명하는 메시지를 출력해야 합니다. 예를 들어, attack() 함수는 다음과 같은 내용을 출력할 수 있습니다 (각괄호는 제외한 내용으로):

__ClapTrap \<name> attacks \<target>, causing \<damage> points of damage!__

The constructors and destructor must also display a message, so your peer-evaluators
can easily see they have been called.
>생성자와 소멸자도 호출되었음을 쉽게 확인할 수 있도록 메시지를 표시해야 합니다.

Implement and turn in your own tests to ensure your code works as expected.
>코드가 예상대로 작동하는지 확인하기 위해 직접 테스트를 구현하고 실행하십시오.

***

# ex01
Because you can never have enough ClapTraps, you will now create a derived robot.
It will be named ScavTrap and will inherit the constructors and destructor from ClapTrap. However, its constructors, destructor and attack() will print different messages.
After all, ClapTraps are aware of their individuality.
>ClapTrap이 충분하지 않다면 파생된 로봇을 생성합니다. 이 로봇은 ScavTrap이라고 하며, ClapTrap에서 생성자와 소멸자를 상속받지만, 생성자, 소멸자 및 attack() 함수는 다른 메시지를 출력할 것입니다. 어차피 ClapTrap들은 자신의 개성을 알고 있습니다.

Note that proper construction/destruction chaining must be shown in your tests.
When a ScavTrap is created, the program starts by building a ClapTrap. Destruction is
in reverse order. Why?
>주의해야 할 점은 테스트에서 적절한 생성/소멸 연결이 표시되어야 합니다. ScavTrap이 생성될 때 프로그램은 먼저 ClapTrap을 구축합니다. 소멸은 역순으로 진행됩니다. 그 이유는 무엇일까요?

ScavTrap will use the attributes of ClapTrap (update ClapTrap in consequence) and
must initialize them to:
>ScavTrap은 ClapTrap의 속성을 사용할 것이며, 그에 따라 ClapTrap을 업데이트해야 합니다. 그리고 이들을 다음과 같이 초기화해야 합니다:

* Name, which is passed as parameter to a constructor
  >이름은 생성자에 전달되는 매개변수로 지정됩니다.
* Hit points (100), represent the health of the ClapTrap
  >히트 포인트(100)는 ClapTrap의 체력을 나타냅니다. ClapTrap과 ScavTrap은 모두 히트 포인트를 100으로 초기화합니다.
* Energy points (50)
  >에너지 포인트(50)
* Attack damage (20)
  >공격 데미지(20)

ScavTrap will also have its own special capacity: void guardGate();
  >ScavTrap은 자체적인 특별한 능력을 갖게 될 것입니다: void guardGate();

This member function will display a message informing that ScavTrap is now in Gate
keeper mode.
>이 멤버 함수는 ScavTrap이 이제 게이트 키퍼 모드에 들어갔음을 알리는 메시지를 표시합니다.

Don’t forget to add more tests to your program.
>프로그램에 더 많은 테스트를 추가하는 것을 잊지 마세요.

***

# ex02
Making ClapTraps is probably starting to get on your nerves.
>클랩트랩을 만드는 것이 아마도 당신의 신경을 거스릴 것입니다.

Now, implement a FragTrap class that inherits from ClapTrap. It is very similar to
ScavTrap. However, its construction and destruction messages must be different. Proper
construction/destruction chaining must be shown in your tests. When a FragTrap is
created, the program starts by building a ClapTrap. Destruction is in reverse order.
>이제 ClapTrap을 상속하는 FragTrap 클래스를 구현하십시오. 이것은 ScavTrap과 매우 비슷합니다. 그러나 생성 및 소멸 메시지는 다르게 해야 합니다. 적절한 생성/소멸 연결이 테스트에 표시되어야 합니다. FragTrap이 생성될 때 프로그램은 먼저 ClapTrap을 구축합니다. 소멸은 역순으로 진행됩니다.

Same things for the attributes, but with different values this time:
>속성에 대해서는 동일한 것들이지만, 이번에는 다른 값으로 초기화해야 합니다:

* Name, which is passed as parameter to a constructor
  >이름은 생성자에 전달되는 매개변수로 지정됩니다.
* Hit points (100), represent the health of the ClapTrap
  >히트 포인트(100)는 ClapTrap의 체력을 나타냅니다. ClapTrap 및 FragTrap은 모두 히트 포인트를 100으로 초기화합니다.
* Energy points (100)
  >에너지 포인트(100)
* Attack damage (30)
  >공격 데미지(30)

FragTrap has a special capacity too: void highFivesGuys(void);
>FragTrap도 특별한 능력을 갖고 있습니다: void highFivesGuys(void);

This member function displays a positive high fives request on the standard output.
>이 멤버 함수는 표준 출력에 긍정적인 하이 파이브 요청을 표시합니다.

Again, add more tests to your program.
>
프로그램에 더 많은 테스트를 추가하세요.

***

# ex03
In this exercise, you will create a monster: a ClapTrap that’s half FragTrap, half
ScavTrap. It will be named DiamondTrap, and it will inherit from both the FragTrap
AND the ScavTrap. This is so risky!
>이 연습에서는 몬스터를 만들 것입니다: FragTrap의 절반과 ScavTrap의 절반으로 이루어진 ClapTrap입니다. 이것은 DiamondTrap이라는 이름을 갖게되며 FragTrap과 ScavTrap 둘 다를 상속받을 것입니다. 이것은 매우 위험합니다!

The DiamondTrap class will have a name private attribute. Give to this attribute
exactly the same variable’s name (not talking about the robot’s name here) than the one
in the ClapTrap base class.
>DiamondTrap 클래스에는 이름 속성이 있습니다. 이 속성의 변수 이름은 ClapTrap 베이스 클래스의 변수 이름과 정확히 동일해야 합니다.

To be more clear, here are two examples.
If ClapTrap’s variable is name, give the name name to the one of the DiamondTrap.
If ClapTrap’s variable is _name, give the name _name to the one of the DiamondTrap.
>더 명확하게 하기 위해 두 가지 예를 들어보겠습니다.
ClapTrap의 변수가 name이면 DiamondTrap의 변수에도 name을 부여합니다.
ClapTrap의 변수가 _name이면 DiamondTrap의 변수에도 _name을 부여합니다.

Its attributes and member functions will be picked from either one of its parent classes:
>그 속성과 멤버 함수는 그 부모 클래스 중 하나에서 선택될 것입니다:

* Name, which is passed as parameter to a constructor
  >이름은 생성자에 전달되는 매개변수로 지정됩니다.
* ClapTrap::name (parameter of the constructor + "_clap_name" suffix)
  >ClapTrap의 이름은 생성자의 매개변수에 "_clap_name" 접미사를 추가하여 설정됩니다.
* Hit points (FragTrap)
  >히트 포인트는 FragTrap에서 상속됩니다.
* Energy points (ScavTrap)
  >에너지 포인트는 ScavTrap에서 상속됩니다.
* Attack damage (FragTrap)
  >공격 데미지는 FragTrap에서 상속됩니다.
* attack() (Scavtrap)
  >attack() 함수는 ScavTrap에서 상속됩니다.

In addition to the special functions of both its parent classes, DiamondTrap will have
its own special capacity: void whoAmI();
>DiamondTrap은 부모 클래스의 특별한 함수들과 함께 자체적인 특별한 기능을 갖게 됩니다: void whoAmI();

This member function will display both its name and its ClapTrap name.
>이 멤버 함수는 자신의 이름과 ClapTrap 이름을 모두 표시합니다.

Of course, the ClapTrap subobject of the DiamondTrap will be created once, and only
once. Yes, there’s a trick.
>물론, DiamondTrap의 ClapTrap 하위 객체는 한 번만 생성됩니다. 네, 한 가지 속임수가 있습니다.

Again, add more tests to your program.
>프로그램에 더 많은 테스트를 추가하세요.

__Do you know the -Wshadow and -Wno-shadow compiler flags?__
>__-Wshadow"와 "-Wno-shadow" 컴파일러 플래그를 알고 계십니까__

__You can pass this module without doing exercise 03.__
>__이 연습을 건너뛰고 이 모듈을 통과할 수 있습니다.__

Turn in your assignment in your Git repository as usual. Only the work inside your
repository will be evaluated during the defense. Don’t hesitate to double check the
names of your folders and files to ensure they are correct.
>평소처럼 귀하의 Git 저장소에 과제를 제출하십시오. 평가는 저장소 내의 작업만 고려됩니다. 폴더 및 파일 이름이 올바른지 확인하기 위해 두 번 확인하는 것이 좋습니다.

