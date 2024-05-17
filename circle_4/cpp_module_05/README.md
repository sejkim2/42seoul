# ex00 : Mommy, when I grow up, I want to be a bureaucrat!

* Turn-in directory : ex00/
* Files to turn in : Makefile, main.cpp, Bureaucrat.{h, hpp}, Bureaucrat.cpp
* Forbidden functions : None

* Please note that exception classes don’t have to be designed in Orthodox Canonical Form. But every other class has to.

Let’s design an artificial nightmare of offices, corridors, forms, and waiting queues.
Sounds fun? No? Too bad.
>

First, start by the smallest cog in this vast bureaucratic machine: the Bureaucrat.
>

A Bureaucrat must have:
>

* A constant name.
  >

* And a grade that ranges from 1 (highest possible grade) to 150 (lowest possible grade).
  >

Any attempt to instantiate a Bureaucrat using an invalid grade must throw an exception: either a Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException.
>

You will provide getters for both these attributes: getName() and getGrade(). Implement also two member functions to increment or decrement the bureaucrat grade. If
the grade is out of range, both of them will throw the same exceptions as the constructor.
>

* Remember. Since grade 1 is the highest one and 150 the lowest, incrementing a grade 3 should give a grade 2 to the bureaucrat.
  >

The thrown exceptions must be catchable using try and catch blocks:
>

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
>

As usual, turn in some tests to prove everything works as expected.
>

# ex01 : Form up, maggots!

* Turn-in directory : ex01/
* Files to turn in : Files from previous exercise + Form.{h, hpp}, Form.cpp
* Forbidden functions : None

Now that you have bureaucrats, let’s give them something to do. What better activity
could there be than the one of filling out a stack of forms?
>

Then, let’s make a __Form__ class. It has:
>

* A constant name.
  >
* A boolean indicating whether it is signed (at construction, it’s not).
  >
* A constant grade required to sign it.
  >
* And a constant grade required to execute it.
  >













































