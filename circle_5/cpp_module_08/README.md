pdf : https://cdn.intra.42.fr/pdf/pdf/115392/en.subject.pdf

# Module-specific rules

You will notice that, in this module, the exercises can be solved WITHOUT the standard
Containers and WITHOUT the standard Algorithms.
> 이 모듈에서 주어진 연습문제들은 표준 컨테이너와 표준 알고리즘 없이 해결할 수 있음을 알 수 있을 것입니다.

However, __using them is precisely the goal of this Module__. You are allowed to
use the STL. Yes, you can use the __Containers__ (vector/list/map/and so forth) and the
__Algorithms__ (defined in header <algorithm>). Moreover, you should use them as much
as you can. Thus, do your best to apply them wherever it’s appropriate.
> 하지만 이 모듈에서는 __그들을 사용하는 것이 목표__ 입니다. 당신은 STL을 사용할 수 있습니다. 네, 당신은 __컨테이너__ (vector/list/map/등)와 __알고리즘__ (헤더 <algorithm>에 정의된)을 사용할 수 있습니다. 더욱이, 최대한 많이 사용해야 합니다. 따라서 적절한 곳에 최대한 적용해 보세요.

You will get a very bad grade if you don’t, even if your code works as expected. Please
don’t be lazy.
> 만약 이를 적용하지 않는다면, 코드가 예상대로 작동하더라도 매우 낮은 점수를 받게 될 것입니다. 게으르지 말아주세요.

You can define your templates in the header files as usual. Or, if you want to, you
can write your template declarations in the header files and write their implementations
in .tpp files. In any case, the header files are mandatory while the .tpp files are optional.
> 템플릿은 보통처럼 헤더 파일에 정의할 수 있습니다. 또는 원하는 경우, 템플릿 선언은 헤더 파일에 작성하고 구현은 .tpp 파일에 작성할 수도 있습니다. 어떤 경우에도 헤더 파일은 필수이지만, .tpp 파일은 선택 사항입니다.

# ex00 : Easy find

* Turn-in directory : ex00/
* Files to turn in : Makefile, main.cpp, easyfind.{h, hpp}
and optional file: easyfind.tpp
* Forbidden functions : None

A first easy exercise is the way to start off on the right foot.
> 첫 번째 쉬운 연습문제는 올바른 발걸음을 시작하는 방법입니다.

Write a function template easyfind that accepts a type T. It takes two parameters.
The first one has type T and the second one is an integer.
> 타입 T를 받는 함수 템플릿 easyfind를 작성하세요. 두 개의 매개변수를 받습니다. 첫 번째 매개변수는 타입 T이고, 두 번째 매개변수는 정수입니다.

Assuming T is a container __of integers__, this function has to find the first occurrence
of the second parameter in the first parameter.
> 타입 T가 __정수__ 의 컨테이너라고 가정할 때, 이 함수는 첫 번째 매개변수에서 두 번째 매개변수의 첫 번째 발생을 찾아야 합니다.

If no occurrence is found, you can either throw an exception or return an error value
of your choice. If you need some inspiration, analyze how standard containers behave.
> 만약 발생을 찾지 못했다면, 예외를 throw하거나 선택한 오류 값으로 반환할 수 있습니다. 영감이 필요하다면, 표준 컨테이너의 동작 방식을 분석해보세요.

Of course, implement and turn in your own tests to ensure everything works as expected
> 물론, 모든 것이 예상대로 작동하는지 확인하기 위해 자신의 테스트를 구현하고 제출하세요.

* You don’t have to handle associative containers.
  > 연관 컨테이너를 처리할 필요는 없습니다.

# ex01 : Span

* Turn-in directory : ex01/
* Files to turn in : Makefile, main.cpp, Span.{h, hpp}, Span.cpp
* Forbidden functions : None

Develop a __Span__ class that can store a maximum of N integers. N is an unsigned int
variable and will be the only parameter passed to the constructor.
> __Span__ 클래스를 개발하여 최대 N개의 정수를 저장할 수 있도록 합니다. N은 부호 없는 정수 변수이며, 생성자에 전달되는 유일한 매개변수입니다.

This class will have a member function called addNumber() to add a single number
to the Span. It will be used in order to fill it. Any attempt to add a new element if there
are already N elements stored should throw an exception.
> 이 클래스에는 Span에 하나의 숫자를 추가하는 addNumber() 멤버 함수가 있을 것입니다. 이 함수는 Span을 채우는 데 사용될 것입니다. 이미 N개의 요소가 저장된 상태에서 새 요소를 추가하려고 시도하면 예외를 발생시켜야 합니다.

Next, implement two member functions: shortestSpan() and longestSpan()
> 다음으로, shortestSpan()과 longestSpan() 두 개의 멤버 함수를 구현하세요.

They will respectively find out the shortest span or the longest span (or distance, if
you prefer) between all the numbers stored, and return it. If there are no numbers stored,
or only one, no span can be found. Thus, throw an exception.
> 이 함수들은 각각 저장된 모든 숫자 사이의 가장 짧은 스팬 또는 가장 긴 스팬(또는 거리, 원하신다면)을 찾아 반환합니다. 숫자가 저장되지 않았거나 한 개만 저장된 경우에는 스팬을 찾을 수 없습니다. 따라서 예외를 발생시켜야 합니다.

Of course, you will write your own tests and they will be way more thorough than the
ones below. Test your Span at least with a minimum of 10 000 numbers. More would be
even better.
> 물론, 여러분은 직접 테스트를 작성하실 것이며, 아래 예시보다 훨씬 철저할 것입니다. Span을 최소 10,000개의 숫자로 테스트하세요. 더 많은 숫자로 테스트하는 것이 더 좋겠습니다.

Running this code:
> 다음 코드를 실행하시오:

```
int main()
{
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
return 0;
}
```

Should output:
> 다음과 같은 결과가 나와야 합니다:

```
$> ./ex01
2
14
$>
```

Last but not least, it would be wonderful to fill your Span using a __range of iterators__.
Making thousands calls to __addNumber()__ is so annoying. Implement a member function
to add many numbers to your Span in one call.
> 마지막으로, __반복자들의 범위__ 를 사용하여 Span을 채우는 것이 좋겠습니다. __addNumber()__ 를 수천 번 호출하는 것은 매우 귀찮습니다. Span에 여러 숫자를 한 번에 추가하는 멤버 함수를 구현하세요.

* If you don’t have a clue, study the Containers. Some member
functions take a range of iterators in order to add a sequence of
elements to the container.
  > 감이 안 오신다면, 컨테이너를 공부해보세요. 일부 멤버 함수는 반복자의 범위를 사용하여 컨테이너에 요소의 시퀀스를 추가합니다.

# ex02 : Mutated abomination

* Turn-in directory : ex02/
* Files to turn in : Makefile, main.cpp, MutantStack.{h, hpp}
and optional file: MutantStack.tpp
* Forbidden functions : None

Now, time to move on more serious things. Let’s develop something weird.
>

The std::stack container is very nice. Unfortunately, it is one of the only STL Containers that is NOT iterable. That’s too bad.
>

But why would we accept this? Especially if we can take the liberty of butchering the
original stack to create missing features.
>

To repair this injustice, you have to make the std::stack container iterable.
>

Write a __MutantStack__ class. It will __be implemented in terms__ of a std::stack.
It will offer all its member functions, plus an additional feature: __iterators__.
>

Of course, you will write and turn in your own tests to ensure everything works as
expected.
>

Find a test example below.
>

```
int main()
{
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl;
mstack.pop();
std::cout << mstack.size() << std::endl;
mstack.push(3);
mstack.push(5);
mstack.push(737);
//[...]
mstack.push(0);
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
++it;
--it;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
std::stack<int> s(mstack);
return 0;
}
```

If you run it a first time with your MutantStack, and a second time replacing the
MutantStack with, for example, a std::list, the two outputs should be the same. Of
course, when testing another container, update the code below with the corresponding
member functions (push() can become push_back()).
>
