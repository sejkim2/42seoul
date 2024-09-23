#include <list>
#include <vector>
#include <iostream>

int main()
{
    std::list<int> l;
    l.push_back(2);
    l.push_back(1);
    l.push_back(3);

    std::list<int>::iterator it = std::lower_bound(l.begin(), l.end(), 3);
    it = it + 1;
}