#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <deque>
using namespace std;

template<typename T>
class A : public std::stack<T, std::deque<T> >
{
};

int main(void)
{
    std::deque<int> d;
    std::vector<int> v;
    std::list<int> l;
    std::stack<int> s(v);

    s.push(1); 
    
}