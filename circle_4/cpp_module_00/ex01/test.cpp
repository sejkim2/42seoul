#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(void)
{
    string str;
    int num;

    getline(cin, str);
    if (cin.eof())
        exit(1);
    cout << str;
    // cin >> str;
    // cout << str;
}