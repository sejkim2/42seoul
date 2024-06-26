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
>

Your iter function template must work with any type of array. The third parameter
can be an instantiated function template.
>

# ex02 : Array
* Turn-in directory : ex02/
* Files to turn in : Makefile, main.cpp, Array.{h, hpp}
and optional file: Array.tpp
* Forbidden functions : None

Develop a class template Array that contains elements of type T and that implements
the following behavior and functions:
>

* Construction with no parameter: Creates an empty array.
  >

* Construction with an unsigned int n as a parameter: Creates an array of n elements
initialized by default. Tip: Try to compile int * a = new int(); then display *a.
  >

* Construction by copy and assignment operator. In both cases, modifying either the
original array or its copy after copying musn’t affect the other array.
  >

* You MUST use the operator new[] to allocate memory. Preventive allocation (allocating memory in advance) is forbidden. Your program must never access nonallocated memory.
  >

* Elements can be accessed through the subscript operator: [ ].
  >

* When accessing an element with the [ ] operator, if its index is out of bounds, an
std::exception is thrown.
  >
* A member function size() that returns the number of elements in the array. This
member function takes no parameter and musn’t modify the current instance.
  >

As usual, ensure everything works as expected and turn in a main.cpp file that contains your tests.
>



































