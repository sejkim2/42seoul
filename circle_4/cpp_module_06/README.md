pdf : https://cdn.intra.42.fr/pdf/pdf/115390/en.subject.pdf

# Additional rule

The following rule applies to the entire module and is not optional.
>

For each exercise, the type conversion must be solved using one specific type of casting.
Your choice will be checked during defense.
>

# ex00 : Conversion of scalar types

* Turn-in directory : ex00/
* Files to turn in : Makefile, *.cpp, *.{h, hpp}
* Allowed functions : Any function to convert from a string to an int, a
float or a double. This will help, but won’t do the whole job.

Write a class ScalarConverter that will contain only one static methods "convert"
that will takes as parameter a string representation of a C++ literal in its most common
form and output its value in the following serie of scalar types :
>

* char
* int
* float
* double

As this class doesn’t need to store anything at all, this class must not be instanciable by users.
>

Except for char parameters, only the decimal notation will be used.
>

Examples of char literals: ’c’, ’a’, ...
>

To make things simple, please note that non displayable characters shouldn’t be used as
inputs. If a conversion to char is not displayable, prints an informative message.
>

Examples of int literals: 0, -42, 42...
>

Examples of float literals: 0.0f, -4.2f, 4.2f...
>

You have to handle these pseudo literals as well (you know, for science): -inff, +inff and nanf.
>

Examples of double literals: 0.0, -4.2, 4.2...
>

You have to handle these pseudo literals as well (you know, for fun): -inf, +inf and nan.
>

Write a program to test that your class works as expected.
>

You have to first detect the type of the literal passed as parameter, convert it from
string to its actual type, then convert it explicitly to the three other data types. Lastly,
display the results as shown below.
>

If a conversion does not make any sense or overflows, display a message to inform
the user that the type conversion is impossible. Include any header you need in order to
handle numeric limits and special values.
>

```
./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0
./convert nan
char: impossible
int: impossible
float: nanf
double: nan
./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0
```

# ex01 : Serialization

* Turn-in directory : ex01/
* Files to turn in : Makefile, *.cpp, *.{h, hpp}
* Forbidden functions : None

Implement a class Serializer, who will not be initializable by the user by any way,
with the following static methods:
>

* uintptr_t serialize(Data* ptr);

It takes a pointer and converts it to the unsigned integer type uintptr_t.
>

* Data* deserialize(uintptr_t raw);

It takes an unsigned integer parameter and converts it to a pointer to Data.
>

Write a program to test that your class works as expected.
>

You must create a non-empty (it means it has data members) Data structure.
>

Use serialize() on the address of the Data object and pass its return value to
deserialize(). Then, ensure the return value of deserialize() compares equal to the
original pointer.
>

Do not forget to turn in the files of your Data structure.
>

# ex02 : Identify real type

* Turn-in directory : ex02/
* Files to turn in : Makefile, *.cpp, *.{h, hpp}
* Forbidden functions : std::typeinfo

Implement a __Base__ class that has a public virtual destructor only. Create three empty
classes __A, B and C,__ that publicly inherit from Base.
>

These four classes don’t have to be designed in the Orthodox Canonical Form.
>

Implement the following functions:
>

* Base * generate(void);

It randomly instanciates A, B or C and returns the instance as a Base pointer. Feel free
to use anything you like for the random choice implementation.
>

* void identify(Base* p);

It prints the actual type of the object pointed to by p: "A", "B" or "C".
>

* void identify(Base& p);

It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer
inside this function is forbidden.
>

Including the typeinfo header is forbidden.
>

Write a program to test that everything works as expected.
>
