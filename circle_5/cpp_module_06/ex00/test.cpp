#include <iostream>
#include <cstdlib>
#include <typeinfo>
using namespace std;

int main(int argc, char **argv)
{
    string str = argv[1];
    char *end;

    // strtod(argv[1], &end);
    //     cout << end;
    size_t f = str.find('.');
    if (f == string::npos)
    {
        int a = static_cast<int>(atoi(argv[1]));
        cout << "type : " << typeid(a).name() << " , value : " << a << endl;
    }
    else
    {
        double a = strtod(argv[1], &end);
        if (*end == 'f')
        {
            float b = static_cast<float>(a);
            cout << "type : " << typeid(b).name() << " , value : " << b << endl;
        }
        else
            cout << "type : " << typeid(a).name() << " , value : " << a << endl;
    }
}