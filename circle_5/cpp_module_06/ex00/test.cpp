#include <iostream>
#include <cstdlib>
#include <typeinfo>
using namespace std;

int main(int argc, char **argv)
{
    string str = argv[1];
    cout << static_cast<char>(atof(argv[1]));
    // size_t findptr = str.find(".");
    // int floatflag = 0;
    
    // if (findptr == string::npos)
    // {
    //     for(size_t i = 0; i<str.length(); i++)
    //     {
    //         if (i == 0 && (str[i] == '-' || str[i] == '+') && str.length() != 1)
    //             continue ;
    //         if (!std::isdigit(str[i]))
    //         {
    //             cout << "is not number\n";
    //             return 0;
    //         }
    //     }
    //     cout << "int : " << str << '\n';
    // }
    // else
    // {
    //     for(size_t i = 0; i<findptr; i++)
    //     {
    //         if (i == 0 && (str[i] == '-' || str[i] == '+') && str.length() != 1)
    //             continue ;
    //         if (!std::isdigit(str[i]))
    //         {
    //             cout << "is not number\n";
    //             return 0;
    //         }
    //     }
    //     if (!std::isdigit(str[findptr - 1]))
    //     {
    //         cout << "is not number 2 \n";
    //         return 0;
    //     }
    //     if (findptr + 1 == str.length())
    //     {
    //         cout << "is not number 2 \n";
    //         return 0;
    //     }
    //     if (str[findptr + 1] == 'f')
    //     {
    //         cout << "is not number 2 \n";
    //         return 0;
    //     }
    //     for(size_t i = findptr + 1; i < str.length(); i++)
    //     {
    //         if (!std::isdigit(str[i]))
    //         {
    //             if (str[i] == 'f' && i == str.length() - 1)
    //             {
    //                 floatflag = 1;
    //                 break ;
    //             }
    //             else
    //             {
    //                 cout << "is not number 3 \n";
    //                 return 0;
    //             }
    //         }
    //     }
    //     if (floatflag == 1)
    //         cout << "float : " << str << '\n';
    //     else
    //         cout << "double : " << str << '\n';
    // }

    // char *end;

    // strtod(argv[1], &end);
    //     cout << end;

    //int -> char
    // char ch = static_cast<char>(atoi(argv[1]));
    // cout << ch;

    // float a = static_cast<float>(0);
    // float a = 0.0f;
    // cout << a;

    /*input : int, double, float*/
    // size_t f = str.find('.');
    // if (f == string::npos)
    // {
    //     int a = static_cast<int>(atoi(argv[1]));
    //     cout << "type : " << typeid(a).name() << " , value : " << a << endl;
    // }
    // else
    // {
    //     double a = strtod(argv[1], &end);
    //     if (*end == 'f')
    //     {
    //         float b = static_cast<float>(a);
    //         cout << "type : " << typeid(b).name() << " , value : " << b << endl;
    //     }
    //     else
    //         cout << "type : " << typeid(a).name() << " , value : " << a << endl;
    // }
}