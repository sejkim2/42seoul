# Introduction
C++ is a general-purpose programming language created by Bjarne Stroustrup as an extension of the C programming language, or "C with Classes" (source: Wikipedia).
>

The goal of these modules is to introduce you to Object-Oriented Programming.
This will be the starting point of your C++ journey. Many languages are recommended
to learn OOP. We decided to choose C++ since it’s derived from your old friend C.
Because this is a complex language, and in order to keep things simple, your code will
comply with the C++98 standard.
>

We are aware modern C++ is way different in a lot of aspects. So if you want to
become a proficient C++ developer, it’s up to you to go further after the 42 Common
Core!
>

You will discover new concepts step-by-step. The exercises will progressively increase
in complexity.
>

# General rules
# Compiling
* Compile your code with c++ and the flags -Wall -Wextra -Werror
* Your code should still compile if you add the flag -std=c++98
# Formatting and naming conventions
* The exercise directories will be named this way: ex00, ex01, ... , exn
* Name your files, classes, functions, member functions and attributes as required in
the guidelines.
* Write class names in UpperCamelCase format. Files containing class code will
always be named according to the class name. For instance:
ClassName.hpp/ClassName.h, ClassName.cpp, or ClassName.tpp. Then, if you
have a header file containing the definition of a class "BrickWall" standing for a
brick wall, its name will be BrickWall.hpp
* Unless specified otherwise, every output messages must be ended by a new-line
character and displayed to the standard output.
* Goodbye Norminette! No coding style is enforced in the C++ modules. You can
follow your favorite one. But keep in mind that a code your peer-evaluators can’t
understand is a code they can’t grade. Do your best to write a clean and readable
code.
# Allowed/Forbidden
# You are not coding in C anymore. Time to C++! Therefore:
* You are allowed to use almost everything from the standard library. Thus, instead
of sticking to what you already know, it would be smart to use as much as possible
the C++-ish versions of the C functions you are used to.
* However, you can’t use any other external library. It means C++11 (and derived
forms) and Boost libraries are forbidden. The following functions are forbidden
too: *printf(), *alloc() and free(). If you use them, your grade will be 0 and
that’s it.
* Note that unless explicitly stated otherwise, the using namespace <ns_name> and
friend keywords are forbidden. Otherwise, your grade will be -42.
* You are allowed to use the STL in the Module 08 and 09 only. That means:
no Containers (vector/list/map/and so forth) and no Algorithms (anything that
requires to include the <algorithm> header) until then. Otherwise, your grade will
be -42.
# A few design requirements
* Memory leakage occurs in C++ too. When you allocate memory (by using the new
keyword), you must avoid memory leaks.
* From Module 02 to Module 09, your classes must be designed in the Orthodox
Canonical Form, except when explicitely stated otherwise.
* Any function implementation put in a header file (except for function templates)
means 0 to the exercise.
* You should be able to use each of your headers independently from others. Thus,
they must include all the dependencies they need. However, you must avoid the
problem of double inclusion by adding include guards. Otherwise, your grade will
be 0.
# Read me
* You can add some additional files if you need to (i.e., to split your code). As these
assignments are not verified by a program, feel free to do so as long as you turn in
the mandatory files.
* Sometimes, the guidelines of an exercise look short but the examples can show
requirements that are not explicitly written in the instructions.
* Read each module completely before starting! Really, do it.
* By Odin, by Thor! Use your brain!!!

* You will have to implement a lot of classes. This can seem tedious,
unless you’re able to script your favorite text editor.

* You are given a certain amount of freedom to complete the exercises.
However, follow the mandatory rules and don’t be lazy. You would
miss a lot of useful information! Do not hesitate to read about
theoretical concepts.

# ex00











































***


#ex01
*입출력 함수 2개
1. cin
-> 공백 전까지
2. getline
-> 델리미터 지정이 없다면 default : 엔터 까지 입력 받음

*cin.fail이 발생하는 경우
1. fd가 닫혀있을 때
2. 파일의 끝에 도달했을 때
3. 잘못된 데이터 형식을 입력했을 때

*cin.fail이 발생했을 때 적절한 처리방법
1. 오류 메시지 출력
2. 오류 플래그 초기화 -> cin.clear()
3. 잘못된 입력으로 인해 비워지지 않은 버퍼 비워주기 -> cin.ignore(buf_size, delim)
delim에 도착할 때까지 버퍼를 지워준다.
만약 버퍼를 비우지 않는다면 다음 입력 시 이전 잘못된 버퍼를 가져오므로 원하는 결과를 얻을 수 없음
₩₩₩
int num;

    std::cout << "정수를 입력하세요: ";
    std::cin >> num;

    if (std::cin.fail())
        std::cout << "잘못된 입력 형식입니다." << std::endl;

    std::cin >> num;
    std::cout << "입력된 정수: " << num << std::endl;
₩₩₩

*find_first_not_of(string)
-> string 중 첫번째로 나오는 문자의 위치 반환

*setw(size)
-> size만큼 너비 지정하여 출력(오른쪽 자동 정렬)

