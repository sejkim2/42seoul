# Introduction
C++ is a general-purpose programming language created by Bjarne Stroustrup as an extension of the C programming language, or "C with Classes" (source: Wikipedia).
>C++은 C 프로그래밍 언어의 확장인 "클래스를 포함한 C"로 알려진 일반 목적의 프로그래밍 언어로, Bjarne Stroustrup에 의해 만들어졌습니다. (출처: 위키피디아)

The goal of these modules is to introduce you to __Object-Oriented Programming__.
This will be the starting point of your C++ journey. Many languages are recommended
to learn OOP. We decided to choose C++ since it’s derived from your old friend C.
Because this is a complex language, and in order to keep things simple, your code will
comply with the C++98 standard.
>이 모듈들의 목표는 객체지향 프로그래밍을 소개하는 것입니다. 이것이 여러분의 C++ 여정의 시작점이 될 것입니다. 많은 언어가 OOP를 배우기를 권장합니다. 우리는 여러분의 옛 친구 C에서 파생된 C++를 선택하기로 결정했습니다. 이 언어는 복잡하기 때문에, 그리고 일관된 것을 유지하기 위해, 여러분의 코드는 C++98 표준을 준수할 것입니다.

We are aware modern C++ is way different in a lot of aspects. So if you want to
become a proficient C++ developer, it’s up to you to go further after the 42 Common
Core!
>우리는 현대 C++가 많은 측면에서 많이 달라졌다는 것을 알고 있습니다. 그래서 만약 여러분이 능숙한 C++ 개발자가 되길 원한다면, 42 Common Core 이후로 더 나아가는 것은 여러분의 선택에 달려 있습니다!

You will discover new concepts step-by-step. The exercises will progressively increase
in complexity.
>여러분은 단계별로 새로운 개념을 발견하게 될 것입니다. 연습문제는 점진적으로 복잡도가 증가할 것입니다.

# General rules
# Compiling
* Compile your code with c++ and the flags -Wall -Wextra -Werror
>c++ 컴파일러를 사용하여 코드를 컴파일하고 -Wall -Wextra -Werror 플래그를 사용하여 경고를 확인할 수 있습니다.
* Your code should still compile if you add the flag -std=c++98
>만약 -std=c++98 플래그를 추가한다고 해도 여전히 코드는 컴파일되어야 합니다.
# Formatting and naming conventions
* The exercise directories will be named this way: ex00, ex01, ... , exn
>연습문제 디렉터리들은 다음과 같이 이름이 지어질 것입니다: ex00, ex01, ..., exn
* Name your files, classes, functions, member functions and attributes as required in
the guidelines.
>가이드라인에서 요구하는 대로 파일, 클래스, 함수, 멤버 함수 및 속성을 이름 지어야 합니다.
* Write class names in __UpperCamelCase__ format. Files containing class code will
always be named according to the class name. For instance:
ClassName.hpp/ClassName.h, ClassName.cpp, or ClassName.tpp. Then, if you
have a header file containing the definition of a class "BrickWall" standing for a
brick wall, its name will be BrickWall.hpp
>클래스 이름은 UpperCamelCase 형식으로 작성해야 합니다. 클래스 코드를 포함하는 파일은 항상 클래스 이름에 따라 명명됩니다. 예를 들어, 클래스 이름이 "ClassName"인 경우 헤더 파일은 ClassName.hpp/ClassName.h로, 소스 파일은 ClassName.cpp로 명명됩니다. 그리고, 만약 벽돌 벽을 나타내는 클래스 "BrickWall"의 정의를 포함하는 헤더 파일이 있다면, 해당 파일의 이름은 BrickWall.hpp가 될 것입니다.
* Unless specified otherwise, every output messages must be ended by a new-line
character and displayed to the standard output.
>특별한 지시가 없는 한, 모든 출력 메시지는 새 줄 문자로 끝나고 표준 출력에 표시되어야 합니다.
* _Goodbye Norminette!_ No coding style is enforced in the C++ modules. You can
follow your favorite one. But keep in mind that a code your peer-evaluators can’t
understand is a code they can’t grade. Do your best to write a clean and readable
code.
>Norminette 안녕! C++ 모듈에서는 코딩 스타일을 강제하지 않습니다. 여러분이 좋아하는 스타일을 따르면 됩니다. 그러나 동료 평가자가 이해할 수 없는 코드는 평가할 수 없는 코드입니다. 깨끗하고 가독성 있는 코드를 작성하는 데 최선을 다하세요.
# Allowed/Forbidden
# You are not coding in C anymore. Time to C++! Therefore:
>그렇습니다! C에서 C++로 넘어왔습니다! 따라서:
* You are allowed to use almost everything from the standard library. Thus, instead
of sticking to what you already know, it would be smart to use as much as possible
the C++-ish versions of the C functions you are used to.
>표준 라이브러리의 거의 모든 것을 사용할 수 있습니다. 따라서 이미 알고 있는 것에 고수하는 대신 가능한 한 많이 C 함수 대신 C++ 스타일의 버전을 사용하는 것이 현명할 것입니다.
* However, you can’t use any other external library. It means C++11 (and derived
forms) and Boost libraries are forbidden. The following functions are forbidden
too: *printf(), *alloc() and free(). If you use them, your grade will be 0 and
that’s it.
>하지만 다른 외부 라이브러리는 사용할 수 없습니다. 즉, C++11 및 파생된 형태와 Boost 라이브러리는 금지됩니다. 다음 함수들도 금지됩니다: printf(), alloc(), free(). 만약 이들을 사용한다면, 여러분의 성적은 0점이 될 것입니다.
* Note that unless explicitly stated otherwise, the using namespace <ns_name> and
friend keywords are forbidden. Otherwise, your grade will be -42.
>암시적으로 다르게 명시되지 않는 한, using namespace <ns_name>과 friend 키워드는 금지됩니다. 그렇지 않다면 여러분의 성적은 -42점이 될 것입니다.
* __You are allowed to use the STL in the Module 08 and 09 only.__ That means:
no __Containers__ (vector/list/map/and so forth) and no __Algorithms__ (anything that
requires to include the <algorithm> header) until then. Otherwise, your grade will
be -42.
>Module 08 및 09에서만 STL을 사용할 수 있습니다. 이는 컨테이너 (vector/list/map/등) 및 알고리즘 (<algorithm> 헤더를 포함해야 하는 모든 것)을 사용할 수 없음을 의미합니다. 그렇지 않으면 여러분의 성적은 -42점이 될 것입니다.
# A few design requirements
* Memory leakage occurs in C++ too. When you allocate memory (by using the new
keyword), you must avoid __memory leaks__.
>C++에서도 메모리 누수가 발생할 수 있습니다. 메모리를 할당할 때 (new 키워드를 사용하여) 메모리 누수를 피해야 합니다.
* From Module 02 to Module 09, your classes must be designed in the __Orthodox
Canonical Form, except when explicitely stated otherwise.__
>Module 02부터 Module 09까지, 클래스는 명시적으로 다르게 명시되지 않는 한 정형 캐노니컬 형식으로 설계되어야 합니다.
* Any function implementation put in a header file (except for function templates)
means 0 to the exercise.
>함수 템플릿을 제외한 헤더 파일에 함수 구현을 넣으면 연습문제에 대해 0점을 받게 됩니다.
* You should be able to use each of your headers independently from others. Thus,
they must include all the dependencies they need. However, you must avoid the
problem of double inclusion by adding __include guards.__ Otherwise, your grade will
be 0.
>각 헤더를 다른 헤더와 독립적으로 사용할 수 있어야 합니다. 따라서 헤더가 필요한 모든 종속성을 포함해야 합니다. 그러나 include guards를 추가하여 이중 포함 문제를 피해야 합니다. 그렇지 않으면 여러분의 성적은 0점이 될 것입니다.
# Read me
* You can add some additional files if you need to (i.e., to split your code). As these
assignments are not verified by a program, feel free to do so as long as you turn in
the mandatory files.
>필요한 경우 코드를 분할하기 위해 몇 가지 추가 파일을 추가할 수 있습니다. 이러한 과제는 프로그램에 의해 확인되지 않으므로 필수 파일을 제출하면 자유롭게 추가할 수 있습니다.
* Sometimes, the guidelines of an exercise look short but the examples can show
requirements that are not explicitly written in the instructions.
>가끔 연습 문제의 지침은 간결하지만 예제에서 명시적으로 쓰여있지 않은 요구 사항을 보여줄 수 있습니다.
* Read each module completely before starting! Really, do it.
>각 모듈을 시작하기 전에 완전히 읽으세요! 정말로요.
* By Odin, by Thor! Use your brain!!!
>오딘의 힘, 토르의 힘을 이용하세요! 당신의 두뇌를 사용하세요!!!

* You will have to implement a lot of classes. This can seem tedious,
unless you’re able to script your favorite text editor.
>당신이 좋아하는 텍스트 편집기를 스크립팅할 수 있다면, 많은 클래스를 구현하는 것이 지루해 보일 수 있습니다.

* You are given a certain amount of freedom to complete the exercises.
However, follow the mandatory rules and don’t be lazy. You would
miss a lot of useful information! Do not hesitate to read about
theoretical concepts.
>연습문제를 완료하기 위해 일정한 자유가 주어집니다. 그러나 필수 규칙을 따르고 게으르지 마십시오. 많은 유용한 정보를 놓칠 수 있습니다! 이론적 개념에 대해 읽는 것을 주저하지 마십시오.

# ex00
* Turn-in directory : ex00/
* Files to turn in : Makefile, megaphone.cpp
* Forbidden functions : None

Just to make sure that everybody is awake, write a program that behaves as follows:
>모두가 깨어있는지 확인하기 위해 다음과 같이 동작하는 프로그램을 작성합니다:

```
$>./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
$>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
$>./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
$>
```
# Solve the exercises in a C++ manner.
>연습문제를 C++ 방식으로 해결합니다.

# ex01 : My Awesome PhoneBook
* Turn-in directory : ex01/
* Files to turn in : Makefile, *.cpp, *.{h, hpp}
* Forbidden functions : None

Welcome to the 80s and their unbelievable technology! Write a program that behaves
like a crappy awesome phonebook software.
>80년대와 그들의 믿기 힘든 기술에 오신 것을 환영합니다! 엉망이지만 멋진 전화번호부 소프트웨어처럼 동작하는 프로그램을 작성해 보겠습니다.

You have to implement two classes:
>두 개의 클래스를 구현해야 합니다:

* PhoneBook
  >전화번호부
  * It has an array of contacts.
  >그것은 연락처의 배열을 가지고 있습니다.
  * It can store a maximum of 8 contacts. If the user tries to add a 9th contact,
replace the oldest one by the new one.
  >최대 8개의 연락처를 저장할 수 있습니다. 사용자가 9번째 연락처를 추가하려고 시도하면 가장 오래된 연락처를 새로운 것으로 교체합니다.
  * Please note that dynamic allocation is forbidden.
  >동적 할당이 금지되어 있음에 유의하세요.
* Contact
  >연락처
  * Stands for a phonebook contact.
  >전화번호부 연락처를 나타냅니다.

In your code, the phonebook must be instantiated as an instance of the PhoneBook
class. Same thing for the contacts. Each one of them must be instantiated as an instance
of the Contact class. You’re free to design the classes as you like but keep in mind that
anything that will always be used inside a class is private, and that anything that can be
used outside a class is public.
>코드에서 전화번호부는 PhoneBook 클래스의 인스턴스로 인스턴스화되어야 합니다. 연락처도 마찬가지입니다. 각각은 Contact 클래스의 인스턴스로 인스턴스화되어야 합니다. 클래스를 원하는 대로 설계할 수 있지만 항상 클래스 내에서 사용될 것은 private이며, 클래스 외부에서 사용될 수 있는 것은 public이라는 것을 기억하세요.

* Don’t forget to watch the intranet videos.
>인트라넷 비디오를 시청하는 것을 잊지 마세요!

* On program start-up, the phonebook is empty and the user is prompted to enter one
of three commands. The program only accepts ADD, SEARCH and EXIT.
>프로그램이 시작되면 전화번호부는 비어 있으며 사용자에게 세 가지 명령 중 하나를 입력하도록 요청됩니다. 프로그램은 ADD, SEARCH 및 EXIT만 허용합니다.

* ADD: save a new contact
  >ADD: 새 연락처 저장
  * If the user enters this command, they are prompted to input the information
of the new contact one field at a time. Once all the fields have been completed,
add the contact to the phonebook.
  >만약 사용자가 이 명령을 입력하면, 새 연락처의 정보를 한 번에 한 필드씩 입력하도록 요청합니다. 모든 필드가 완료되면, 연락처를 전화번호부에 추가합니다.
  * The contact fields are: first name, last name, nickname, phone number, and
darkest secret. A saved contact can’t have empty fields.
  >연락처 필드는 이름, 성, 별명, 전화번호 및 가장 비밀스러운 비밀입니다. 저장된 연락처는 빈 필드를 가질 수 없습니다.

* SEARCH: display a specific contact
  >SEARCH: 특정 연락처 표시
  * Display the saved contacts as a list of 4 columns: index, first name, last
name and nickname.
  >저장된 연락처를 4개의 열로 표시합니다: 인덱스, 이름, 성, 별명.
  * Each column must be 10 characters wide. A pipe character (’|’) separates
them. The text must be right-aligned. If the text is longer than the column,
it must be truncated and the last displayable character must be replaced by a
dot (’.’).
  >각 열은 10자리 너비여야 합니다. 파이프 문자 ('|')가 각 열을 구분합니다. 텍스트는 오른쪽 정렬되어야 합니다. 텍스트가 열보다 긴 경우 잘릴 것이며, 마지막으로 표시 가능한 문자는 점 ('.')으로 대체됩니다.
  * Then, prompt the user again for the index of the entry to display. If the index
is out of range or wrong, define a relevant behavior. Otherwise, display the
contact information, one field per line.
  >그런 다음 사용자에게 다시 항목을 표시할 인덱스에 대해 프롬프트합니다. 인덱스가 범위를 벗어나거나 잘못된 경우 관련된 동작을 정의하세요. 그렇지 않으면, 연락처 정보를 한 줄에 하나씩 표시합니다.

* EXIT
  * The program quits and the contacts are lost forever!
  >프로그램이 종료되고 연락처는 영원히 사라집니다!

* Any other input is discarded.
>다른 모든 입력은 무시됩니다.

Once a command has been correctly executed, the program waits for another one. It
stops when the user inputs EXIT.
>한 번 명령이 올바르게 실행되면, 프로그램은 다른 명령을 기다립니다. 사용자가 EXIT를 입력하면 프로그램이 멈춥니다.

Give a relevant name to your executable.
>당신의 실행 파일에 적절한 이름을 지정하세요.

https://cplusplus.com/reference/string/string/ and of course
https://cplusplus.com/reference/iomanip/

# ex02 : The Job Of Your Dreams

* Turn-in directory : ex02/
* Files to turn in : Makefile, Account.cpp, Account.hpp, tests.cpp
* Forbidden functions : None
* Account.hpp, tests.cpp and the log file are available for download on
the intranet page of the module.
>Account.hpp, tests.cpp 및 로그 파일은 해당 모듈의 인트라넷 페이지에서 다운로드할 수 있습니다.

Today is your first day at GlobalBanksters United. After successfully passing the recruitment tests (thanks to a few Microsoft Office tricks a friend showed you), you joined
the dev team. You also know the recruiter was amazed by how quickly you installed
Adobe Reader. That little extra made all the difference and helped you defeat all your
opponents (aka the other applicants): you made it!
>오늘은 글로벌뱅스터즈 유나이티드에서의 첫 날입니다. 친구가 보여 준 몇 가지 마이크로소프트 오피스 트릭 덕분에 채용 테스트를 성공적으로 통과한 후에 개발 팀에 합류했습니다. 또한 당신이 얼마나 빨리 Adobe Reader를 설치했는지에 대해 인상을받았다는 것을 인사담당자가 알고 있습니다. 그 작은 추가가 모든 차이를 만들었고 다른 지원자들, 즉 모든 경쟁자를 이기는 데 도움이 되었습니다. 당신은 성공했습니다!

Anyway, your manager just gave you some work to do. Your first task is to recreate a
lost file. Something went wrong and a source file was deleted by mistake. Unfortunately,
your colleagues don’t know what Git is and use USB keys to share code. At this point, it
would make sense to leave this place right now. However, you decide to stay. Challenge
accepted!
>어쨌든, 당신의 매니저가 당신에게 할 일을 줬습니다. 첫 번째 작업은 손실된 파일을 재생성하는 것입니다. 어떤 문제가 발생하여 소스 파일이 실수로 삭제되었습니다. 불행히도, 당신의 동료들은 Git이 무엇인지 모르고 코드를 공유하기 위해 USB 키를 사용합니다. 이 시점에서는 지금 이곳을 떠나는 것이 합리적일 것 같습니다. 그러나 당신은 머물기로 결정합니다. 도전 수락했습니다!

Your fellow developers give you a bunch of files. Compiling tests.cpp reveals that
the missing file is Account.cpp. Lucky you, the header file Account.hpp was saved.
There is also a log file. Maybe you could use it in order to understand how the Account
class was implemented.
>당신의 동료 개발자들이 여러 파일을 제공합니다. tests.cpp를 컴파일하면 누락된 파일이 Account.cpp임을 알 수 있습니다. 운이 좋게도 Account.hpp 헤더 파일이 저장되어 있습니다. 또한 로그 파일도 있습니다. 아마도 이 로그 파일을 활용하여 Account 클래스가 어떻게 구현되었는지 이해할 수 있을 것입니다.

You start to recreate the Account.cpp file. In only a few minutes, you code a few
lines of pure awesome C++. After a couple of failed compilations, your program passes
the tests. Its output matches perfectly the one saved in the log file (except for the
timestamps which will obviously differ since the tests saved in the log file were run
before you were hired).
>멋진 C++ 코드 몇 줄을 몇 분 안에 작성했습니다! 정말 멋지네요. 계속해서 진행하시겠습니까? 도움이 필요하시면 언제든지 말씀해주세요! 몇 번의 컴파일 실패 후에, 당신의 프로그램이 테스트를 통과합니다. 그 출력 결과는 로그 파일에 저장된 것과 완벽하게 일치합니다 (당연히 타임스탬프는 다를 것입니다. 왜냐하면 로그 파일에 저장된 테스트는 당신이 고용되기 전에 실행되었기 때문입니다).

Damn, you’re impressive!
>당신은 인상적이세요!

The order in which the destructors are called may differ depending on
your compiler/operating system. So your destructors may be called in
a reverse order.
>소멸자가 호출되는 순서는 컴파일러나 운영 체제에 따라 달라질 수 있습니다. 따라서 당신의 소멸자는 반대 순서로 호출될 수 있습니다.

You can pass this module without doing exercise 02.
>Exercise 02를 수행하지 않고도 이 모듈을 통과할 수 있습니다.

# Submission and peer-evaluation
Turn in your assignment in your Git repository as usual. Only the work inside your
repository will be evaluated during the defense. Don’t hesitate to double check the
names of your files to ensure they are correct.
>평소처럼 귀하의 Git 저장소에 과제를 제출하십시오. 방어 시에는 저장소 내의 작업만 평가됩니다. 파일 이름이 정확한지 확인하기 위해 두 번 확인하는 것을 주저하지 마십시오.

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

