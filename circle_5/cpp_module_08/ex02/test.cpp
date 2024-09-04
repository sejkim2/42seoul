#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <deque>
using namespace std;

template<typename T>
class A : public std::stack<T, std::vector<T>>
{
public:
    // 기본 생성자
    A() : std::stack<T, std::vector<T>>() {}

    // 복사 생성자
    A(const A& other) : std::stack<T, std::vector<T>>(other) {}
};

int main(void)
{
    A<int> a;
    a.push(4);
    cout << a.top();

    std::stack<int> s(vector<int> );
}