#include <iostream>
#include "iter.hpp"
using namespace std;

int main(void)
{
    int *arr = new int[20];

    ::iter(arr, 20, save<int>);
    ::iter(arr, 20, print<int>);
}