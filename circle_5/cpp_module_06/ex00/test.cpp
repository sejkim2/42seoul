#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    std::string str = "42.3";
    char ch = str[0];
    double d = static_cast<double>(ch);
    int n = static_cast<int>(d);
    float f = static_cast<float>(d);
    cout << ch << endl << n << endl << f << endl << d << endl;
}
