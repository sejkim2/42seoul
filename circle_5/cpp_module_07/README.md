pdf : https://cdn.intra.42.fr/pdf/pdf/115391/en.subject.pdf

# ex00 : Start with a few functions

* Turn-in directory : ex00/
* Files to turn in : Makefile, main.cpp, whatever.{h, hpp}
* Forbidden functions : None

Implement the following function templates:
> 다음 함수 템플릿을 구현하십시오:

* swap: Swaps the values of two given arguments. Does not return anything.
  > swap: 두 주어진 인수의 값을 서로 바꿉니다. 아무것도 반환하지 않습니다.

* min: Compares the two values passed in its arguments and returns the smallest
one. If the two of them are equal, then it returns the second one.
  > min: 전달된 두 값을 비교하여 작은 값을 반환합니다. 만약 두 값이 같다면, 두 번째 값을 반환합니다.

* max: Compares the two values passed in its arguments and returns the greatest one.
If the two of them are equal, then it returns the second one.
  > max: 전달된 두 값을 비교하여 큰 값을 반환합니다. 만약 두 값이 같다면, 두 번째 값을 반환합니다.

These functions can be called with any type of argument. The only requirement is
that the two arguments must have the same type and must support all the comparison
operators.
> 이 함수들은 어떤 유형의 인수로도 호출될 수 있습니다. 유일한 요구 사항은 두 인수가 동일한 유형이어야 하며, 모든 비교 연산자를 지원해야 한다는 것입니다.

* Templates must be defined in the header files.
  > 템플릿은 헤더 파일에 정의되어야 합니다.

Running the following code:
> 다음 코드를 실행하시오:

```
int main( void ) {
int a = 2;
int b = 3;
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
std::string c = "chaine1";
std::string d = "chaine2";
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
return 0;
}
```
Should output:
> 다음과 같은 결과가 나와야 합니다:

```
a = 3, b = 2
min(a, b) = 2
max(a, b) = 3
c = chaine2, d = chaine1
min(c, d) = chaine1
max(c, d) = chaine2
```

# ex01 : Iter

* Turn-in directory : ex01/
* Files to turn in : Makefile, main.cpp, iter.{h, hpp}
* Forbidden functions : None

Implement a function template iter that takes 3 parameters and returns nothing.
> 3개의 매개변수를 받고 아무것도 반환하지 않는 함수 템플릿 iter를 구현하십시오.

* The first parameter is the address of an array.
  > 첫 번째 매개변수는 배열의 주소입니다.

* The second one is the length of the array.
  > 두 번째 매개변수는 배열의 길이입니다.

* The third one is a function that will be call on every element of the array.
  > 세 번째 매개변수는 배열의 각 요소에 대해 호출될 함수입니다.

Turn in a main.cpp file that contains your tests. Provide enough code to generate a
test executable.
> 당신의 테스트가 포함된 main.cpp 파일을 제출해 주세요. 실행 가능한 테스트용 실행 파일을 생성할 수 있도록 충분한 코드를 제공해주세요.

Your iter function template must work with any type of array. The third parameter
can be an instantiated function template.
> 당신의 iter 함수 템플릿은 어떤 유형의 배열에도 작동해야 합니다. 세 번째 매개변수는 인스턴스화된 함수 템플릿일 수 있습니다.

# ex02 : Array
* Turn-in directory : ex02/
* Files to turn in : Makefile, main.cpp, Array.{h, hpp}
and optional file: Array.tpp
* Forbidden functions : None

Develop a class template Array that contains elements of type T and that implements
the following behavior and functions:
> 클래스 템플릿 Array를 개발하여 요소의 유형이 T인 기능과 함수를 구현하세요.

* Construction with no parameter: Creates an empty array.
  > Construction with no parameter: 빈 배열을 생성합니다.

* Construction with an unsigned int n as a parameter: Creates an array of n elements
initialized by default. Tip: Try to compile int * a = new int(); then display *a.
  > 부호 없는 정수 n을 매개변수로 사용하는 생성자: 기본값으로 초기화된 n개의 요소를 가진 배열을 생성합니다. 팁: int *a = new int();를 컴파일한 다음, *a를 출력해 보세요.

* Construction by copy and assignment operator. In both cases, modifying either the
original array or its copy after copying musn’t affect the other array.
  > 복사 생성자와 대입 연산자를 통한 생성. 두 경우 모두, 복사 후 원본 배열이나 복사본 배열을 수정해도 다른 배열에 영향을 미치지 않아야 합니다.

* You MUST use the operator new[] to allocate memory. Preventive allocation (allocating memory in advance) is forbidden. Your program must never access nonallocated memory.
  > 메모리 할당을 위해 `operator new[]`를 반드시 사용해야 합니다. 사전 할당(미리 메모리를 할당하는 것)은 금지되어 있습니다. 프로그램은 할당되지 않은 메모리에 절대 접근해서는 안 됩니다.

* Elements can be accessed through the subscript operator: [ ].
  > 요소는 서브스크립트 연산자: [ ]를 통해 접근할 수 있습니다.

* When accessing an element with the [ ] operator, if its index is out of bounds, an
std::exception is thrown.
  > [ ] 연산자를 사용하여 요소에 접근할 때, 인덱스가 범위를 벗어나면 std::exception이 발생합니다.
* A member function size() that returns the number of elements in the array. This
member function takes no parameter and musn’t modify the current instance.
  > 배열의 요소 개수를 반환하는 멤버 함수 size(). 이 멤버 함수는 매개변수를 받지 않으며 현재 인스턴스를 수정해서는 안 됩니다.

As usual, ensure everything works as expected and turn in a main.cpp file that contains your tests.
> 항상 그렇듯이, 모든 것이 예상대로 작동하는지 확인하고 테스트가 포함된 `main.cpp` 파일을 제출하세요.

