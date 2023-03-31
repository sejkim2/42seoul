# 42cursus - libft

/*주소 연산 시 unsigned char *로 형변환 하는 이유*/ (byte padding : strchr)
명시적으로 그러한 규칙을 강제하지는 않지만, unsigned char로 접근할 때만
잘 정의된 동작을 한다는 결론을 간접적으로 도출할 수 있습니다.
unsigned char의 내부 표현은 padding이 없이 모든 비트가 value bit라는 
점이 특징입니다. 즉 trap representation이 없다는 뜻이죠.
실제로 접하기 어려운 환경이지만 예를 들어 signed char로 double형 변수에
접근할 경우 padding bit로 인해 trap representation에 걸릴 수 있습니다.

unsigned char 는 모든 bit 를 투명하게 볼 수 있는 특성을 제공합니다.
즉, 다른 type 은 내부 비트의 일부를 값을 표현하기 위한 용도가 아닌
다른 용도로 사용할 수 있으나 unsigned char 는 이것이 허락되지
않습니다.
따라서, 임의의 메모리에 바이트 단위로 접근해 값을 다룰 때에는 반드시
unsigned char 를 사용해야 full portability 를 얻을 수 있는 것입니다.
또한, 그와 같은 이유로 signed char 가 표현할 수 있는 값의 개수보다
unsigned char 가 표현할 수 있는 값의 개수가 많다는 사실에도 유의할
필요가 있습니다. signed char <-> unsigned char 사이의 값 변환이 1:1
로 이루어질 수 "없는" 경우도 있음을 의미합니다.
이와 같은 이유로, 표준이 바이트 값에 접근해야 하는 경우나 문자에
접근해야 하는 경우 (예: mem*(), str*() 함수들) 에는 모두 unsigned char
로 접근하도록 요구하고 있습니다. 책에서는 memcpy 함수를 흉내내는
것이기 때문에 그런 사항을 반영해 unsigned char 를 사용했습니다.
예전에 이곳에서도 비슷한 논의가 있었던 것으로 기억합니다만, 꼭 padding
bit 가 아니어도 null character 의 정의에 의해 문제가 될 수 있는 경우가
있습니다. signed char 는 1s' complement 표현이나 sign-magnitude
표현에서 -0 을 가질 수도 있습니다 - 이 경우 sign bit 가 1 이 됩니다.
하지만, null character 의 정의는 (sign bit 포함해) 모든 비트가 0 이길
요구하고 있습니다. 즉, -0 은 null character 가 될 수 없는 것입니다.
따라서 이를 올바르게 구분해내기 위해서는 unsigned char 로 접근해야
하는 것입니다.

/*int로 받은 인자를 char로 바꾸는 이유*/
오늘날의 C와 다르게 예전에는
매개변수(혹은 인자)를 안에 안적어주거나,
char *strchr();
인자를 적어도 type을 안적어주는 prototype으로 작성
char *strchr(s, c);
이런 코딩스타일이였기에 그 값이 설령 char로 이용된다하더라도, 컴퓨터는 일단 이를 int로 처리하고, 이후에 함수 내부에서 char로 변환되는 식
그리고 현재의 C에서도 prototype이 없거나 printf처럼 가변인자를 받는 경우에는 모두 이와같은 방식(int로 일단 처리하는)으로 동작

/*size_t를 사용하는 이유*/
32bit os에서는 size_t는 부호 없는 32비트 정수이다 (os마다 달라짐)
unsigned int는 os 안에서도 비트 수를 결정할 수 없기 때문에 불안정하다.
(사실 size_t의 정확한 의미는 현재 시스템이 한번에 처리할 수 있는 가장 큰 크기를 말한다.)

NULL vs 0 vs '\0'
NULL과 0은 주소에 저장될 수 있으며 아스키 값은 0이고 널 포인터라고 부른다. 보통 포인터가 가리키는 곳이 없을 때 초기화 하기 위해 사용한다. 자료형은 포인터형 이다.
'\0'은 널 문자로 아스키코드에서는 0x30이다. 자료형은 char 이다.
(사용자 입장에서는 NULL이 0보다 더 직관적으로 느껴진다.)

strlcat
