# ex00 : Mommy, when I grow up, I want to be a bureaucrat!

* Turn-in directory : ex00/
* Files to turn in : Makefile, main.cpp, Bureaucrat.{h, hpp}, Bureaucrat.cpp
* Forbidden functions : None

* Please note that exception classes don’t have to be designed in Orthodox Canonical Form. But every other class has to.
  > 예외 클래스는 정통 정형 형식(Orthodox Canonical Form)으로 설계될 필요는 없습니다. 하지만 다른 모든 클래스는 그렇게 해야 합니다.

Let’s design an artificial nightmare of offices, corridors, forms, and waiting queues.
Sounds fun? No? Too bad.
>사무실, 복도, 서류 양식, 그리고 대기 줄로 이루어진 인공적인 악몽을 디자인해 봅시다.
재미있나요? 아니요? 안타깝네요.

First, start by the smallest cog in this vast bureaucratic machine: the Bureaucrat.
>먼저, 이 방대한 관료 기계의 가장 작은 톱니바퀴인 관료부터 시작하세요.

A Bureaucrat must have:
>관료는 다음을 갖추어야 합니다:

* A constant name.
  >일정한 이름.

* And a grade that ranges from 1 (highest possible grade) to 150 (lowest possible grade).
  >그리고 1등급(가장 높은 등급)부터 150등급(가장 낮은 등급)까지의 등급.

Any attempt to instantiate a Bureaucrat using an invalid grade must throw an exception: either a Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException.
>잘못된 등급으로 관료를 인스턴스화하려는 모든 시도는 Bureaucrat::GradeTooHighException 또는 Bureaucrat::GradeTooLowException 중 하나의 예외를 던져야 합니다.

You will provide getters for both these attributes: getName() and getGrade(). Implement also two member functions to increment or decrement the bureaucrat grade. If the grade is out of range, both of them will throw the same exceptions as the constructor.
>이 두 속성에 대해 getName()과 getGrade() 게터를 제공해야 합니다. 또한 관료의 등급을 증가시키거나 감소시키는 두 개의 멤버 함수를 구현해야 합니다. 등급이 범위를 벗어나면, 두 함수 모두 생성자와 동일한 예외를 던져야 합니다.

* Remember. Since grade 1 is the highest one and 150 the lowest, incrementing a grade 3 should give a grade 2 to the bureaucrat.
  >기억하세요. 등급 1이 가장 높고 150이 가장 낮으므로, 등급 3을 증가시키면 관료에게는 등급 2가 주어져야 합니다.

The thrown exceptions must be catchable using try and catch blocks:
>발생한 예외는 try-catch 블록을 사용하여 잡을 수 있어야 합니다.

```
try
{
/* do some stuff with bureaucrats */
}
catch (std::exception & e)
{
/* handle exception */
}
```

You will implement an overload of the insertion («) operator to print something like
(without the angle brackets):\<name\>, bureaucrat grade \<grade\>.
> «삽입(«) 연산자의 오버로드를 구현하여 다음과 같이 출력해야 합니다(꺾쇠 괄호 없이): <이름>, 관료 등급 <등급>.»

As usual, turn in some tests to prove everything works as expected.
>평소처럼 모든 것이 예상대로 작동하는지 증명하기 위해 몇 가지 테스트를 제출하십시오.

# ex01 : Form up, maggots!

* Turn-in directory : ex01/
* Files to turn in : Files from previous exercise + Form.{h, hpp}, Form.cpp
* Forbidden functions : None

Now that you have bureaucrats, let’s give them something to do. What better activity
could there be than the one of filling out a stack of forms?
>이제 당신에게 관료가 있으니, 그들에게 할 일을 주어보죠. 어떤 활동이 서류 더미를 채우는 것보다 더 좋을까요?

Then, let’s make a __Form__ class. It has:
>그럼, __Form__ 클래스를 만들어 봅시다. 이 클래스는 다음을 갖습니다:

* A constant name.
  >일정한 이름.

* A boolean indicating whether it is signed (at construction, it’s not).
  >서명되었는지를 나타내는 부울 값(생성 시에는 서명되지 않음).

* A constant grade required to sign it.
  >서명하는 데 필요한 일정한 등급.

* And a constant grade required to execute it.
  >그리고 실행하는 데 필요한 일정한 등급.

All these attributes are private, not protected.
>모든 이러한 속성은 비공개(private)이며, 보호(protected)되지 않습니다.

The grades of the __Form__ follow the same rules that apply to the Bureaucrat. Thus,
the following exceptions will be thrown if a form grade is out of bounds:
Form::GradeTooHighException and Form::GradeTooLowException.
> __Form__ 의 등급은 관료(Bureaucrat)에 적용되는 동일한 규칙을 따릅니다. 따라서, 만약 Form의 등급이 범위를 벗어나면 다음과 같은 예외가 발생할 것입니다: Form::GradeTooHighException과 Form::GradeTooLowException.

Same as before, write getters for all attributes and an overload of the insertion («)
operator that prints all the form’s informations.
>이전과 마찬가지로, 모든 속성에 대한 게터를 작성하고 삽입(«) 연산자를 오버로드하여 모든 폼 정보를 출력하겠습니다

Add also a beSigned() member function to the Form that takes a Bureaucrat as
parameter. It changes the form status to signed if the bureaucrat’s grade is high enough
(higher or egal to the required one). Remember, grade 1 is higher than grade 2.
If the grade is too low, throw a Form::GradeTooLowException.
>또한, Form에 Bureaucrat을 매개변수로 사용하여 서명하는 beSigned() 멤버 함수를 추가하겠습니다. 이 함수는 관료의 등급이 충분히 높을 경우 (요구되는 등급보다 높거나 같을 경우) 폼 상태를 서명된 상태로 변경합니다. 기억해 주세요, 등급 1은 등급 2보다 높습니다. 등급이 너무 낮으면 Form::GradeTooLowException을 던집니다.

Lastly, add a signForm() member function to the Bureaucrat. If the form got signed,
it will print something like:
>마지막으로, Bureaucrat에 signForm() 멤버 함수를 추가합니다. 폼이 서명되면 다음과 같이 출력됩니다:

* \<bureaucrat\> signed \<form\>

* Otherwise, it will print something like:
  >그렇지 않으면, 다음과 같이 출력됩니다:
* \<bureaucrat\> couldn’t sign \<form\> because \<reason\>.

* Implement and turn in some tests to ensure everything works as expected.
  >예상대로 모든 것이 작동하는지 확인하기 위해 몇 가지 테스트를 구현하고 제출하겠습니다.

# ex02 : No, you need form 28B, not 28C...

* Turn-in directory : ex02/
* Files to turn in : Makefile, main.cpp, Bureaucrat.[{h, hpp},cpp],
Bureaucrat.cpp + AForm.[{h, hpp},cpp], ShrubberyCreationForm.[{h, hpp},cpp], +
RobotomyRequestForm.[{h, hpp},cpp], PresidentialPardonForm.[{h, hpp},cpp]
* Forbidden functions : None

Since you now have basic forms, it’s time to make a few more that actually do something.
>이제 기본적인 양식이 있으므로, 실제로 무언가를 수행하는 몇 가지 더 만들어 보겠습니다.

In all cases, the base class Form must be an abstract class, and therefore should be
renamed AForm. Keep in mind the form’s attributes need to remain private and that
they are in the base class.
>모든 경우에 기본 클래스 Form은 추상 클래스여야 하므로, 따라서 이름을 AForm으로 변경해야 합니다. 양식의 속성은 비공개(private)로 유지되어야 하며, 이들은 기본 클래스에 있어야 합니다.

Add the following concrete classes:
>다음의 구체적인 클래스를 추가하겠습니다:

* __ShrubberyCreationForm__: Required grades: sign 145, exec 137
Create a file \<target\>_shrubbery in the working directory, and writes ASCII trees
inside it.
  >__ShrubberyCreationForm__: 필요한 등급: 서명 145, 실행 137
작업 디렉터리에 \<target\>_shrubbery 파일을 생성하고 그 안에 ASCII 나무를 작성합니다.

* __RobotomyRequestForm__: Required grades: sign 72, exec 45
Makes some drilling noises. Then, informs that \<target\> has been robotomized
successfully 50% of the time. Otherwise, informs that the robotomy failed.
  > __RobotomyRequestForm__: 필요한 등급: 서명 72, 실행 45 일부 드릴 소리를 만듭니다. 그런 다음, \<target\>이(가) 50%의 확률로 성공적으로 로보토미 처리되었음을 알립니다. 그렇지 않으면, 로보토미가 실패했음을 알립니다.

* PresidentialPardonForm: Required grades: sign 25, exec 5
Informs that \<target\> has been pardoned by Zaphod Beeblebrox.
  >PresidentialPardonForm: 필요한 등급: 서명 25, 실행 5
\<target\>이(가) Zaphod Beeblebrox에 의해 사면되었음을 알립니다.

All of them take only one parameter in their constructor: the target of the form. For
example, "home" if you want to plant shrubbery at home.
>모두 생성자에서 하나의 매개변수만 가져야 합니다: 양식의 대상입니다. 예를 들어, 집에 수목을 심고 싶다면 "home"을 사용합니다.

Now, add the execute(Bureaucrat const & executor) const member function to
the base form and implement a function to execute the form’s action of the concrete
classes. You have to check that the form is signed and that the grade of the bureaucrat
attempting to execute the form is high enough. Otherwise, throw an appropriate exception.
>이제 기본 양식에 execute(Bureaucrat const & executor) const 멤버 함수를 추가하고, 구체적인 클래스의 양식 동작을 실행하는 함수를 구현하겠습니다. 양식이 서명되었는지와 양식을 실행하려는 관료의 등급이 충분히 높은지를 확인해야 합니다. 그렇지 않으면, 적절한 예외를 던져야 합니다.

Whether you want to check the requirements in every concrete class or in the base
class (then call another function to execute the form) is up to you. However, one way is
prettier than the other one.
>각 구체 클래스에서 요구 사항을 확인할지, 아니면 기본 클래스에서 확인한 다음 다른 함수를 호출하여 양식을 실행할지는 선택입니다. 그러나 한 가지 방법이 다른 방법보다 더 예쁩니다.

Lastly, add the executeForm(AForm const & form) member function to the Bureaucrat. It must attempt to execute the form. If it’s successful, print something like:
>마지막으로, Bureaucrat에 executeForm(AForm const & form) 멤버 함수를 추가합니다. 양식을 실행하려고 시도해야 합니다. 성공하면 다음과 같이 출력해야 합니다:

* \<bureaucrat\> executed \<form\>

* If not, print an explicit error message.
  >그렇지 않으면 명시적인 오류 메시지를 출력합니다.

* Implement and turn in some tests to ensure everything works as expected.
  >예상대로 모든 것이 작동하는지 확인하기 위해 몇 가지 테스트를 구현하고 제출하겠습니다.

# ex03 : At least this beats coffee-making

* Turn-in directory : ex03/
* Files to turn in : Files from previous exercises + Intern.{h, hpp}, Intern.cpp
* Forbidden functions : None

Because filling out forms is annoying enough, it would be cruel to ask our bureaucrats
to do this all day long. Fortunately, interns exist. In this exercise, you have to implement
the __Intern__ class. The intern has no name, no grade, no unique characteristics. The only
thing the bureaucrats care about is that they do their job.
>서류 작성이 이미 귀찮은 일이므로, 우리의 관료들에게 이를 하루 종일 계속해서 요청하는 것은 잔인할 것입니다. 다행히도, 인턴이 존재합니다. 이 연습에서는 __Intern__ 클래스를 구현해야 합니다. 인턴은 이름도, 등급도, 독특한 특성도 없습니다. 관료들이 신경 쓰는 유일한 것은 인턴들이 일을 잘하는 것입니다.

However, the intern has one important capacity: the makeForm() function. It takes
two strings. The first one is the name of a form and the second one is the target of the
form. It return a pointer to a __Form object__ (whose name is the one passed as parameter)
whose target will be initialized to the second parameter.
>하지만, 인턴은 한 가지 중요한 능력이 있습니다: makeForm() 함수입니다. 이 함수는 두 개의 문자열을 가져옵니다. 첫 번째는 양식의 이름이고, 두 번째는 양식의 대상입니다. 두 번째 매개변수로 초기화된 대상을 가진 __Form 객체__ 포인터(이름이 매개변수로 전달된 것과 같은)를 반환합니다.

* It will print something like:
  > 다음과 같이 출력됩니다:

* Intern creates \<form\>

If the form name passed as parameter doesn’t exist, print an explicit error message.
>매개변수로 전달된 양식 이름이 존재하지 않는 경우, 명시적인 오류 메시지를 출력합니다.

You must avoid unreadable and ugly solutions like using a if/elseif/else forest. This
kind of things won’t be accepted during the evaluation process. You’re not in Piscine
(pool) anymore. As usual, you have to test that everything works as expected.
>if/elseif/else 숲과 같이 가독성이 떨어지고 추한 해결책을 피해야 합니다. 평가 과정에서는 이러한 종류의 해결책을 허용하지 않을 것입니다. 당신은 더 이상 피신에 있지 않습니다. 모든 것이 예상대로 작동하는지 확인하기 위해 테스트해야 합니다.

For example, the code below creates a __RobotomyRequestForm__ targeted on "Bender":
>예를 들어, 아래 코드는 "벤더"를 대상으로 하는 __RobotomyRequestForm__를 만듭니다:

```
{
Intern someRandomIntern;
Form* rrf;
rrf = someRandomIntern.makeForm("robotomy request", "Bender");
}
```



# ex00
관료의 등급 설정할 때 1 ~ 150 의 정수가 아니면 예외 처리
# ex01
form이 추가됨, 
