#include <iostream>
#include "func.hpp"

// int main(void)
// {
//     int n1 = 10;
//     int n2 = 20;

//     cout << "[before swap] n1 : " << n1 << " " << "n2 : " << n2 << endl;
//     ::swap(n1, n2);
//     cout << "[after swap] n1 : " << n1 << " " << "n2 : " << n2 << endl;

//     cout << "[max] : " << ::max(n1, n2) << endl;
//     cout << "[min] : " << ::min(n1, n2) << endl;
// }

int main( void ) {
const int a = 2;
const int b = 3;
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