pdf : https://cdn.intra.42.fr/pdf/pdf/115345/en.subject.pdf

# Module-specific rules

It is mandatory to use the standard containers to perform each exercise in this module.
> 이 모듈의 각 연습문제를 수행할 때 표준 컨테이너를 사용하는 것이 필수입니다.

Once a container is used you cannot use it for the rest of the module
> 한 번 컨테이너를 사용하면 이후 모듈에서는 사용할 수 없습니다.

* It is advisable to read the subject in its entirety before doing the
exercises.
  > 연습 문제를 하기 전에 주제를 전체적으로 읽는 것이 바람직합니다.

* You must use at least one container for each exercise with the
exception of exercise 02 which requires the use of two containers.
  > 각 연습 문제마다 적어도 하나의 STL 컨테이너를 사용해야 하며, 단, 연습 문제 02는 두 개의 STL 컨테이너를 사용해야 합니다

You must submit a Makefile for each program which will compile your source files
to the required output with the flags -Wall, -Wextra and -Werror.
> 각 프로그램에 대해 소스 파일을 컴파일하여 요구된 출력 결과를 생성하는 Makefile을 제출해야 하며, 컴파일할 때는 -Wall, -Wextra 및 -Werror 플래그를 사용해야 합니다.

You must use c++, and your Makefile must not relink.
> C++를 사용해야 하며, Makefile은 재링크를 하지 않아야 합니다.

Your Makefile must at least contain the rules $(NAME), all, clean, fclean and re.
> Makefile에는 최소한 $(NAME), all, clean, fclean, re 규칙이 포함되어야 합니다.

# ex00 : Bitcoin Exchange

*Turn-in directory : ex00/
* Files to turn in : Makefile, main.cpp, BitcoinExchange.{cpp, hpp}
* Forbidden functions : None

You have to create a program which outputs the value of a certain amount of bitcoin
on a certain date.
> 특정 날짜에 특정 양의 비트코인 가치가 출력되는 프로그램을 만들어야 합니다.

This program must use a database in csv format which will represent bitcoin price
over time. This database is provided with this subject.
> 이 프로그램은 시간에 따른 비트코인 가격을 나타내는 CSV 형식의 데이터베이스를 사용해야 하며, 이 데이터베이스는 주어진 주제와 함께 제공됩니다.

The program will take as input a second database, storing the different prices/dates
to evaluate.
> 프로그램은 평가할 다양한 가격/날짜를 저장하는 두 번째 데이터베이스를 입력으로 받습니다.

Your program must respect these rules:
> 프로그램은 다음 규칙을 준수해야 합니다:

* The program name is btc.
  > 프로그램 이름은 `btc`입니다.

* Your program must take a file as argument.
  > 프로그램은 파일을 인수로 받아야 합니다.

* Each line in this file must use the following format: "date | value".
  > 이 파일의 각 줄은 다음 형식을 사용해야 합니다: "날짜 | 값".

* A valid date will always be in the following format: Year-Month-Day.
  > 유효한 날짜는 항상 다음 형식이어야 합니다: 연도-월-일.

* A valid value must be either a float or a positive integer, between 0 and 1000.
  > 유효한 값은 0과 1000 사이의 양수 정수이거나 실수여야 합니다.

* You must use at least one container in your code to validate this
exercise. You should handle possible errors with an appropriate
error message.
  > 코드에서 이 연습 문제를 검증하기 위해 최소한 하나의 컨테이너를 사용해야 합니다. 가능한 오류는 적절한 오류 메시지로 처리해야 합니다.

Here is an example of an input.txt file:
> 다음은 `input.txt` 파일의 예입니다:

```
$> head input.txt
date | value
2011-01-03 | 3
2011-01-03 | 2
2011-01-03 | 1
2011-01-03 | 1.2
2011-01-09 | 1
2012-01-11 | -1
2001-42-42
2012-01-11 | 1
2012-01-11 | 2147483648
$>
```

Your program will use the value in your input file.
> 프로그램은 입력 파일의 값을 사용할 것입니다.

Your program should display on the standard output the result of the value multiplied
by the exchange rate according to the date indicated in your database.
> 프로그램은 데이터베이스에 명시된 날짜에 따른 환율로 값이 곱해진 결과를 표준 출력에 표시해야 합니다.

* If the date used in the input does not exist in your DB then you
must use the closest date contained in your DB. Be careful to use the
lower date and not the upper one.
  > 입력에 사용된 날짜가 데이터베이스에 존재하지 않으면, 데이터베이스에 포함된 가장 가까운 날짜를 사용해야 합니다. 이때 상한 날짜가 아닌 하한 날짜를 사용해야 합니다.

The following is an example of the program’s use.
> 다음은 프로그램 사용의 예입니다:

```
$> ./btc
Error: could not open file.
$> ./btc input.txt
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-03 => 1 = 0.3
2011-01-03 => 1.2 = 0.36
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42
2012-01-11 => 1 = 7.1
Error: too large a number.
$>
```

* Warning: The container(s) you use to validate this exercise will no
longer be usable for the rest of this module.
  > 경고: 이 연습 문제를 검증하는 데 사용하는 컨테이너는 이 모듈의 나머지 부분에서는 사용할 수 없습니다.

# ex01 : Reverse Polish Notation

* Turn-in directory : ex01/
* Files to turn in : Makefile, main.cpp, RPN.{cpp, hpp}
* Forbidden functions : None

You must create a program with these constraints:
> 다음 제약 조건을 가진 프로그램을 만들어야 합니다:

* The program name is RPN.
  > 프로그램 이름은 `RPN`입니다.

* Your program must take an inverted Polish mathematical expression as an argument.
  > 프로그램은 역폴란드 수식(중위 표기법의 반대)을 인수로 받아야 합니다.

* The numbers used in this operation and passed as arguments will always be less
than 10. The calculation itself but also the result do not take into account this rule.
  > 이 연산에 사용되는 숫자와 인수로 전달되는 숫자는 항상 10보다 작습니다. 그러나 계산 자체와 결과는 이 규칙을 따르지 않습니다.

* Your program must process this expression and output the correct result on the
standard output.
  > 프로그램은 이 수식을 처리하고 표준 출력에 올바른 결과를 출력해야 합니다.

* If an error occurs during the execution of the program an error message should be
displayed on the standard output.
  > 프로그램 실행 중 오류가 발생하면, 표준 출력에 오류 메시지를 표시해야 합니다.

* Your program must be able to handle operations with these tokens: "+ - / *".
  > 프로그램은 다음 연산자 토큰을 처리할 수 있어야 합니다: "+ - / *".

* You must use at least one container in your code to validate this
exercise.
  > 코드에서 이 연습 문제를 검증하기 위해 최소한 하나의 컨테이너를 사용해야 합니다.

* You don’t need to manage the brackets or decimal numbers.
  > 괄호나 소수점 숫자는 처리할 필요가 없습니다.

Here is an example of a standard use:
> 다음은 표준 사용의 예입니다:

```
$> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
$> ./RPN "7 7 * 7 -"
42
$> ./RPN "1 2 * 2 / 2 * 2 4 - +"
0
$> ./RPN "(1 + 1)"
Error
$>
```

* Warning: The container(s) you used in the previous exercise are
forbidden here. The container(s) you used to validate this exercise
will not be usable for the rest of this module.
  > 경고: 이전 연습 문제에서 사용한 컨테이너는 여기에서 사용할 수 없습니다. 이 연습 문제를 검증하는 데 사용한 컨테이너는 이 모듈의 나머지 부분에서 사용할 수 없습니다.

# ex02 : PmergeMe

* Turn-in directory : ex02/
* Files to turn in : Makefile, main.cpp, PmergeMe.{cpp, hpp}
* Forbidden functions : None

You must create a program with these constraints:
>

* The name of the program is PmergeMe.
  >

* Your program must be able to use a positive integer sequence as argument.
  >

* Your program must use the merge-insert sort algorithm to sort the positive integer sequence.
  >

* To clarify, yes, you need to use the Ford-Johnson algorithm.
  >

* If an error occurs during program execution, an error message should be displayed
on the standard output.
  >

* You must use at least two different containers in your code to
validate this exercise. Your program must be able to handle at
least 3000 different integers.
  >

* It is strongly advised to implement your algorithm for each container
and thus to avoid using a generic function.
  >

Here are some additional guidelines on the information you should display line by line
on the standard output:
>

* On the first line you must display an explicit text followed by the unsorted positive
integer sequence.
  >

* On the second line you must display an explicit text followed by the sorted positive
integer sequence.
  >

* On the third line you must display an explicit text indicating the time used by
your algorithm by specifying the first container used to sort the positive integer
sequence.
  >

* On the last line you must display an explicit text indicating the time used by
your algorithm by specifying the second container used to sort the positive integer
sequence.
  >

* The format for the display of the time used to carry out your sorting
is free but the precision chosen must allow to clearly see the
difference between the two containers used.
  >

Here is an example of a standard use:
>

```
$> ./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::[..] : 0.00031 us
Time to process a range of 5 elements with std::[..] : 0.00014 us
$> ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
Before: 141 79 526 321 [...]
After: 79 141 321 526 [...]
Time to process a range of 3000 elements with std::[..] : 62.14389 us
Time to process a range of 3000 elements with std::[..] : 69.27212 us
$> ./PmergeMe "-1" "2"
Error
$> # For OSX USER:
$> ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
[...]
$>
```

* The indication of the time is deliberately strange in this example.
Of course you have to indicate the time used to perform all your
operations, both the sorting part and the data management part.
  >

* Warning: The container(s) you used in the previous exercises are
forbidden here.
  >

* The management of errors related to duplicates is left to your
discretion.
  >
