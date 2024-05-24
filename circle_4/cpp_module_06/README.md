pdf : https://cdn.intra.42.fr/pdf/pdf/115390/en.subject.pdf

# Additional rule

The following rule applies to the entire module and is not optional.
>다음 규칙은 전체 모듈에 적용되며 선택 사항이 아닙니다.

For each exercise, the type conversion must be solved using one specific type of casting.
Your choice will be checked during defense.
>각 연습 문제마다, 형 변환은 하나의 특정한 캐스팅 유형을 사용하여 해결해야 합니다. 당신의 선택은 발표 중에 확인될 것입니다.

# ex00 : Conversion of scalar types

* Turn-in directory : ex00/
* Files to turn in : Makefile, *.cpp, *.{h, hpp}
* Allowed functions : Any function to convert from a string to an int, a
float or a double. This will help, but won’t do the whole job.

Write a class ScalarConverter that will contain only one static methods "convert"
that will takes as parameter a string representation of a C++ literal in its most common
form and output its value in the following serie of scalar types :
>클래스 `ScalarConverter`를 작성하십시오. 이 클래스는 하나의 정적 메서드 "convert"만 포함할 것입니다. 이 메서드는 가장 일반적인 형태의 C++ 리터럴 문자열 표현을 매개변수로 받아서 다음 일련의 스칼라 유형으로 값을 출력할 것입니다:

* char
* int
* float
* double

As this class doesn’t need to store anything at all, this class must not be instanciable by users.
>이 클래스는 아무것도 저장할 필요가 없기 때문에, 사용자에 의해 인스턴스화될 수 없어야 합니다.

Except for char parameters, only the decimal notation will be used.
>char 매개변수를 제외하고는, 오직 십진법 표기만 사용될 것입니다.

Examples of char literals: ’c’, ’a’, ...
>char 리터럴의 예: 'c', 'a', ...

To make things simple, please note that non displayable characters shouldn’t be used as
inputs. If a conversion to char is not displayable, prints an informative message.
>간단하게 하기 위해, 표시할 수 없는 문자는 입력으로 사용되지 않는다는 점을 유의하세요. 만약 char로의 변환이 표시할 수 없는 경우, 정보를 제공하는 메시지를 출력합니다.

Examples of int literals: 0, -42, 42...
>int 리터럴의 예: 0, -42, 42...

Examples of float literals: 0.0f, -4.2f, 4.2f...
>float 리터럴의 예: 0.0f, -4.2f, 4.2f...

You have to handle these pseudo literals as well (you know, for science): -inff, +inff and nanf.
>당신이 알겠지만, "과학"을 위해 이러한 의사 리터럴도 처리해야 합니다: -inff, +inff, nanf.

Examples of double literals: 0.0, -4.2, 4.2...
>double 리터럴의 예: 0.0, -4.2, 4.2...

You have to handle these pseudo literals as well (you know, for fun): -inf, +inf and nan.
>당신이 알겠지만, 재미를 위해 이러한 의사 리터럴도 처리해야 합니다: -inf, +inf, nan.

Write a program to test that your class works as expected.
>당신의 클래스가 예상대로 작동하는지 확인하기 위한 프로그램을 작성하세요.

You have to first detect the type of the literal passed as parameter, convert it from
string to its actual type, then convert it explicitly to the three other data types. Lastly,
display the results as shown below.
>먼저 매개변수로 전달된 리터럴의 유형을 감지한 후에, 문자열에서 실제 유형으로 변환한 다음 명시적으로 다른 세 가지 데이터 유형으로 변환해야 합니다. 마지막으로 아래와 같이 결과를 표시합니다.

If a conversion does not make any sense or overflows, display a message to inform
the user that the type conversion is impossible. Include any header you need in order to
handle numeric limits and special values.
>만약 변환이 의미가 없거나 오버플로우가 발생한다면, 사용자에게 형 변환이 불가능하다는 메시지를 표시합니다. 특수 값 및 숫자 한계를 처리하기 위해 필요한 헤더를 포함하십시오.

```
./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0
./convert nan
char: impossible
int: impossible
float: nanf
double: nan
./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0
```

# ex01 : Serialization

* Turn-in directory : ex01/
* Files to turn in : Makefile, *.cpp, *.{h, hpp}
* Forbidden functions : None

Implement a class Serializer, who will not be initializable by the user by any way,
with the following static methods:
>사용자가 아무런 방법으로도 초기화할 수 없는 클래스 Serializer를 구현하고, 다음과 같은 정적 메서드를 가집니다:

* uintptr_t serialize(Data* ptr);

It takes a pointer and converts it to the unsigned integer type uintptr_t.
>포인터를 받아서 unsigned integer 타입인 uintptr_t로 변환합니다.

* Data* deserialize(uintptr_t raw);

It takes an unsigned integer parameter and converts it to a pointer to Data.
>unsigned integer 매개변수를 받아서 이를 Data 포인터로 변환합니다.

Write a program to test that your class works as expected.
>클래스가 예상대로 작동하는지 테스트하기 위한 프로그램을 작성하세요.

You must create a non-empty (it means it has data members) Data structure.
>데이터 멤버를 가진 비어 있지 않은 Data 구조를 만들어야 합니다.

Use serialize() on the address of the Data object and pass its return value to
deserialize(). Then, ensure the return value of deserialize() compares equal to the
original pointer.
>Data 객체의 주소에 serialize()를 사용하고, 그 반환 값을 deserialize()에 전달합니다. 그런 다음, deserialize()의 반환 값이 원래 포인터와 동일한지 확인합니다.

Do not forget to turn in the files of your Data structure.
>Data 구조의 파일을 제출하는 것을 잊지 마세요.

# ex02 : Identify real type

* Turn-in directory : ex02/
* Files to turn in : Makefile, *.cpp, *.{h, hpp}
* Forbidden functions : std::typeinfo

Implement a __Base__ class that has a public virtual destructor only. Create three empty
classes __A, B and C,__ that publicly inherit from Base.
>다음과 같이 오직 공개 가상 소멸자를 가진 __Base__ 클래스를 구현합니다. __A, B, C__ 라는 세 개의 빈 클래스를 만들고, 이들은 모두 __Base__ 를 공개 상속합니다.

These four classes don’t have to be designed in the Orthodox Canonical Form.
>이 네 개의 클래스는 정형 표준 형식으로 디자인할 필요가 없습니다.

Implement the following functions:
>다음 함수들을 구현하세요:

* Base * generate(void);

It randomly instanciates A, B or C and returns the instance as a Base pointer. Feel free
to use anything you like for the random choice implementation.
>랜덤하게 A, B 또는 C를 생성하고 이를 Base 포인터로 반환하는 함수를 구현합니다. 랜덤 선택 구현에 사용할 것을 자유롭게 선택하세요.

* void identify(Base* p);

It prints the actual type of the object pointed to by p: "A", "B" or "C".
>p가 가리키는 객체의 실제 유형을 출력합니다: "A", "B" 또는 "C".

* void identify(Base& p);

It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer
inside this function is forbidden.
>p가 가리키는 객체의 실제 유형을 출력합니다: "A", "B", 또는 "C". 이 함수 내에서 포인터 사용은 금지되어 있습니다.

Including the typeinfo header is forbidden.
>typeinfo 헤더를 포함하는 것은 금지되어 있습니다.

Write a program to test that everything works as expected.
>모든 것이 예상대로 작동하는지 테스트하기 위한 프로그램을 작성하세요.
