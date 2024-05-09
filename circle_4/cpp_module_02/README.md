# New rules

From now on, all your classes must be designed in the Orthodox Canonical Form,
unless explicitely stated otherwise. Then, they will implement the four required member
functions below:
>이제부터, 모든 당신의 수업은 명시적으로 다른 방법이 지정되지 않는 한, Orthodox Canonical Form으로 설계되어야 합니다. 그 후에는 아래의 네 가지 필수 멤버 함수를 구현해야 합니다.
* Default constructor
  >기본 생성자
* Copy constructor
  >복사 생성자
* Copy assignment operator
  >복사 대입 연산자
* Destructor
  >소멸자
Split your class code into two files. The header file (.hpp/.h) contains the class
definition whereas the source file (.cpp) contains the implementation.
>클래스 코드를 두 개의 파일로 나누세요. 헤더 파일(.hpp/.h)에는 클래스 정의가 포함되고, 소스 파일(.cpp)에는 구현이 포함됩니다.

# ex00 : My First Class in Orthodox Canonical Form
* Turn-in directory : ex00/
* Files to turn in : Makefile, main.cpp, Fixed.{h, hpp}, Fixed.cpp
* Forbidden functions : None

You think you know integers and floating-point numbers. How cute.
>정수와 부동 소수점 숫자를 알고 있다고 생각하는군요. 귀엽네요.

Please read this 3 pages article ([1](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html), [2](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_representation.html) [3](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_printing.html)) to discover that you don’t. Go on, read it.
>제가 읽지 않음을 발견할 수 있도록 이 3 페이지 기사를 읽어보세요. 계속 읽어 보세요.([1](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html), [2](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_representation.html) [3](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_printing.html))

Until today, every number you used in your code was basically either an integer or a
floating-point number, or any of their variants (short, char, long, double, and so forth).
After reading the article above, it’s safe to assume that integers and floating-point numbers have opposite caracteristics.
>지금까지, 당신이 코드에서 사용한 모든 숫자는 기본적으로 정수 또는 부동 소수점 숫자이거나 그 변형(짧은 정수, 문자, 긴 정수, 더블 등) 중 하나였습니다. 위의 기사를 읽은 후에는 정수와 부동 소수점 숫자가 상반된 특성을 가지고 있다고 가정해도 안전할 것으로 생각됩니다.

But today, things will change. You are going to discover a new and awesome number
type: __fixed-point numbers!__ Forever missing from the scalar types of most languages,
fixed-point numbers offer a valuable balance between performance, accuracy, range and
precision. That explains why fixed-point numbers are particularly applicable to computer
graphics, sound processing or scientific programming, just to name a few.
>하지만 오늘부터는 상황이 바뀔 것입니다. 새롭고 멋진 숫자 형식을 발견하게 될 거에요: **고정 소수점 숫자(fixed-point numbers)!** 대부분의 언어의 스칼라 유형에서 빠져있던 고정 소수점 숫자는 성능, 정확도, 범위 및 정밀도 사이에서 가치 있는 균형을 제공합니다. 이것이 왜 고정 소수점 숫자가 컴퓨터 그래픽스, 음향 처리 또는 과학 프로그래밍 등에 특히 적용되는지 설명해줍니다.

As C++ lacks fixed-point numbers, you’re going to add them. [This article](https://inst.eecs.berkeley.edu/~cs61c/sp06/handout/fixedpt.html) from
Berkeley is a good start. If you have no idea what Berkeley University is, read [this
section](https://en.wikipedia.org/wiki/University_of_California,_Berkeley#Notable_alumni.2C_faculty.2C_and_staff) of its Wikipedia page.
>C++은 고정 소수점 숫자를 지원하지 않기 때문에, 여러분이 이를 추가할 것입니다. 버클리 대학교의 이 기사는 좋은 시작입니다. 버클리 대학교가 무엇인지 모르는 경우, 해당 위키백과 페이지의 이 섹션을 읽어보세요.

Create a class in Orthodox Canonical Form that represents a fixed-point number:
>고정소수점 숫자를 나타내는 정규식 형식의 클래스를 생성하겠습니다.
* Private members:
  
  * An integer to store the fixed-point number value.
  >고정소수점 숫자 값을 저장하기 위한 정수형 변수.
  
  * A static constant integer to store the number of fractional bits. Its value will always be the integer literal 8.
  >소수 비트 수를 저장하는 정적 상수 정수입니다. 그 값은 항상 정수 리터럴 8입니다.

* Public members:

  * A default constructor that initializes the fixed-point number value to 0.
  >기본 생성자는 고정 소수점 숫자 값을 0으로 초기화합니다.
  
  * A copy constructor.
  >복사 생성자
  
  * A copy assignment operator overload.
  >복사 대입 연산자
  
  * A destructor.
  >소멸자
  
  * A member function int getRawBits( void ) const;

  * that returns the raw value of the fixed-point value.
  >고정 소수점 값의 원시 값을 반환하는 함수입니다.
  
  * A member function void setRawBits( int const raw );

  * that sets the raw value of the fixed-point number.
  >고정 소수점 숫자의 원시 값을 설정하는 함수입니다.

Running this code:
>이 코드를 실행하세요:

```
#include <iostream>
int main( void ) {
Fixed a;
Fixed b( a );
Fixed c;
c = b;
std::cout << a.getRawBits() << std::endl;
std::cout << b.getRawBits() << std::endl;
std::cout << c.getRawBits() << std::endl;
return 0;
}
```
Should output something similar to:
>비슷한 형태의 출력을 얻어야 합니다.

```
$> ./a.out
Default constructor called
Copy constructor called
Copy assignment operator called // <-- This line may be missing depending on your implementation
getRawBits member function called
Default constructor called
Copy assignment operator called
getRawBits member function called
getRawBits member function called
0
getRawBits member function called
0
getRawBits member function called
0
Destructor called
Destructor called
Destructor called
$>
```

# ex01 : Towards a more useful fixed-point number class
* Turn-in directory : ex01/
* Files to turn in : Makefile, main.cpp, Fixed.{h, hpp}, Fixed.cpp
* Allowed functions : roundf (from <cmath>)

The previous exercise was a good start but our class is pretty useless. It can only
represent the value 0.0.
>이전 예제는 좋은 출발이었지만 우리 클래스는 꽤 쓸모없습니다. 단지 0.0 값을 나타낼 뿐이에요.

Add the following public constructors and public member functions to your class:
>당신의 클래스에 다음과 같은 공개 생성자 및 공개 멤버 함수를 추가하세요:

* A constructor that takes a constant integer as a parameter.
>상수 정수를 매개변수로 사용하는 생성자입니다.

It converts it to the corresponding fixed-point value. The fractional bits value is
initialized to 8 like in exercise 00.
>그것을 해당 고정소수점 값으로 변환합니다. 소수 비트 값은 연습 00과 마찬가지로 8로 초기화됩니다.

* A constructor that takes a constant floating-point number as a parameter.
>그것을 해당 고정소수점 값으로 변환합니다. 소수 비트 값은 연습 00과 마찬가지로 8로 초기화됩니다.

* A member function float toFloat( void ) const;
that converts the fixed-point value to a floating-point value.
>고정 소수점 값을 부동 소수점 값으로 변환합니다.

* A member function int toInt( void ) const;
that converts the fixed-point value to an integer value.
>고정 소수점 값을 정수 값으로 변환합니다.

And add the following function to the Fixed class files:
>그리고 다음 함수를 Fixed 클래스 파일에 추가하세요:

* An overload of the insertion («) operator that inserts a floating-point representation of the fixed-point number into the output stream object passed as parameter.
>매개변수로 전달된 출력 스트림 객체에 고정 소수점 숫자의 부동 소수점 표현을 삽입하는 삽입(«) 연산자의 오버로드입니다.

Running this code:
>이 코드를 실행하세요:
```
#include <iostream>
int main( void ) {
Fixed a;
Fixed const b( 10 );
Fixed const c( 42.42f );
Fixed const d( b );
a = Fixed( 1234.4321f );
std::cout << "a is " << a << std::endl;
std::cout << "b is " << b << std::endl;
std::cout << "c is " << c << std::endl;
std::cout << "d is " << d << std::endl;
std::cout << "a is " << a.toInt() << " as integer" << std::endl;
std::cout << "b is " << b.toInt() << " as integer" << std::endl;
std::cout << "c is " << c.toInt() << " as integer" << std::endl;
std::cout << "d is " << d.toInt() << " as integer" << std::endl;
return 0;
}
```
Should output something similar to:
>비슷한 형태의 출력을 얻어야 합니다.

```
$> ./a.out
Default constructor called
Int constructor called
Float constructor called
Copy constructor called
Copy assignment operator called
Float constructor called
Copy assignment operator called
Destructor called
a is 1234.43
b is 10
c is 42.4219
d is 10
a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer
Destructor called
Destructor called
Destructor called
Destructor called
$>
```

# ex02 : Now we’re talking
* Turn-in directory : ex02/
* Files to turn in : Makefile, main.cpp, Fixed.{h, hpp}, Fixed.cpp
* Allowed functions : roundf (from <cmath>)

Add public member functions to your class to overload the following operators:
>당신의 클래스에 다음의 연산자를 오버로드하기 위한 공개 멤버 함수를 추가하세요:

* The 6 comparison operators: >, <, >=, <=, == and !=.
  >6개의 비교 연산자를 오버로드하는 공개 멤버 함수를 추가하세요: >, <, >=, <=, ==, 그리고 !=.

* The 4 arithmetic operators: +, -, *, and /.
  >사칙 연산자인 +, -, *, 그리고 /를 오버로드하는 공개 멤버 함수를 추가하세요.

* The 4 increment/decrement (pre-increment and post-increment, pre-decrement and
post-decrement) operators, that will increase or decrease the fixed-point value from
the smallest representable ϵ such as 1 + ϵ > 1.
>가능한 작은 ϵ (예: 1 + ϵ > 1)에서 고정 소수점 값을 증가시키거나 감소시키는 4개의 증가/감소 연산자(pre-
increment, post-increment, pre-decrement, post-decrement)를 추가하세요.

Add these four public overloaded member functions to your class:
>당신의 클래스에 다음 네 가지 공개된 오버로드된 멤버 함수를 추가하세요:

* A static member function min that takes as parameters two references on fixed-point
numbers, and returns a reference to the smallest one.
>두 개의 고정소수점 숫자에 대한 참조를 매개변수로 취하고, 더 작은 것에 대한 참조를 반환하는 정적 멤버 함수 min을 추가하세요.

* A static member function min that takes as parameters two references to constant
fixed-point numbers, and returns a reference to the smallest one.
>두 개의 상수 고정 소수점 숫자에 대한 참조를 매개변수로 취하고, 더 작은 것에 대한 참조를 반환하는 정적 멤버 함수 min을 추가하세요.

* A static member function max that takes as parameters two references on fixed-point
numbers, and returns a reference to the greatest one.
>두 개의 고정 소수점 숫자에 대한 참조를 매개변수로 취하고, 가장 큰 것에 대한 참조를 반환하는 정적 멤버 함수 max를 추가하세요.

* A static member function max that takes as parameters two references to constant
fixed-point numbers, and returns a reference to the greatest one.
>두 개의 상수 고정 소수점 숫자에 대한 참조를 매개변수로 취하고, 가장 큰 것에 대한 참조를 반환하는 정적 멤버 함수 max를 추가하세요.

It’s up to you to test every feature of your class. However, running the code below:
>당신의 클래스의 모든 기능을 테스트하는 것은 당신에게 달려 있습니다. 하지만 아래의 코드를 실행하는 것은요:

```
#include <iostream>
int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}
```
Should output something like (for greater readability, the constructor/destructor messages are removed in the example below):
>다음과 같은 출력이 나와야 할 것입니다 (가독성을 높이기 위해 생성자/소멸자 메시지는 아래 예시에서 제거되었습니다):

```
$> ./a.out
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
$>
```
If you ever do a division by 0, it is acceptable that the program crashes
>만약 0으로 나누기를 하게 되면 프로그램이 충돌하는 것은 허용됩니다.

# ex03 : BSP
* Turn-in directory : ex03/
* Files to turn in : Makefile, main.cpp, Fixed.{h, hpp}, Fixed.cpp,
* Point.{h, hpp}, Point.cpp, bsp.cpp
* Allowed functions : roundf (from <cmath>)

Now that you have a functional Fixed class, it would be nice to use it.
Implement a function which indicates whether a point is inside of a triangle or not.
>이제 작동하는 Fixed 클래스가 있으므로 그것을 사용하는 것이 좋겠네요. 삼각형 내부에 점이 있는지 여부를 나타내는 함수를 구현해보겠습니다.
Very useful, isn’t it?
BSP stands for Binary space partitioning. You are welcome. :)
You can pass this module without doing exercise 03.
>정말 유용하죠, 맞죠? BSP는 Binary Space Partitioning의 약자입니다. 환영합니다. :) Exercise 03을 수행하지 않고 이 모듈을 통과할 수 있습니다.

Let’s start by creating the class Point in Orthodox Canonical Form that represents a 2D point:
>오케이, 2차원 점을 나타내는 정규식 형식의 Point 클래스를 만들어보죠.
* Private members:

  * A Fixed const attribute x.
  >고정된 const 속성 x.
  
  * A Fixed const attribute y.
  >고정된 const 속성 y.
  
  * Anything else useful.
  >다른 유용한 것이 있을까요?

* Public members:

  * A default constructor that initializes x and y to 0.
  >x와 y를 0으로 초기화하는 기본 생성자입니다.
  
  * A constructor that takes as parameters two constant floating-point numbers. It initializes x and y with those parameters.
  >두 개의 상수 부동 소수점 숫자를 매개변수로 사용하는 생성자입니다. 이 생성자는 해당 매개변수로 x와 y를 초기화합니다.

  * A copy constructor.
    >복사 생성자

  * A copy assignment operator overload.
    >복사 대입 연산자 오버로드입니다.

  * A destructor.
    >소멸자

  * Anything else useful.
    >다른 유용한 것이 있을까요?

To conclude, implement the following function in the appropriate file:
>마무리로, 적절한 파일에 다음 함수를 구현하세요:

* bool bsp( Point const a, Point const b, Point const c, Point const point);

* a, b, c: The vertices of our beloved triangle.
  >a, b, c : 우리가 사랑하는 삼각형의 꼭지점입니다.

* point: The point to check.
  >point: 확인할 점입니다.

* Returns: True if the point is inside the triangle. False otherwise.
  >반환값: 점이 삼각형 내부에 있으면 True를 반환하고, 그렇지 않으면 False를 반환합니다.

Thus, if the point is a vertex or on edge, it will return False.
Implement and turn in your own tests to ensure that your class behaves as expected.
>따라서, 점이 꼭지점이거나 변 위에 있는 경우에는 False를 반환합니다. 클래스가 예상대로 동작하는지 확인하기 위해 직접 테스트를 구현하고 제출하세요.
