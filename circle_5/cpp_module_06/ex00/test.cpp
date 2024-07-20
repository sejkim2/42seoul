#include <iostream>
#include <cstdlib>
#include <typeinfo>
using namespace std;

int main(int argc, char **argv)
{
    string str = argv[1];
    string str2 = str.substr(0, str.find("."));
    cout << str2;
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