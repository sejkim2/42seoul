#include <iostream>
using namespace std;

class A
{
    public:
        A() : n(0) {
            cout << "default constructor" << '\n';
            member = new int[n];
        }
        ~A() {
            // cout << "default destroctor" << '\n';
            delete[] member;
        }
        A(int tmp) : n(tmp) {
            member = new int[tmp];
        }
        A(const A& copy) {
            cout << "copy constructor" << '\n';
            *this = copy;
        }
        A& operator=(const A& obj) {
            cout << "asignment operator" << '\n';
            delete[] member;
            member = new int[obj.n];
            return (*this);
        }

        int* member;
        int n;
};

int main()
{
    // A a1;
    // A a2;
    // a1 = a2;
    A a2;
    A a3 = a2;
    // A a3(a2); // A a3 = a2;
}