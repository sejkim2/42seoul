#include <iostream>
#include <vector>

std::vector<int>::iterator func(void)
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    return v.begin();
}

int main()
{
    std::vector<int>::const_iterator it = func();
    
}