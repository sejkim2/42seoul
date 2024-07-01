#include <iostream>
#include <cstdlib>
using namespace std;


int main(int argc, char **argv)
{
    string str = argv[1];
    char *end;
    double a = strtod(argv[1], &end);
    cout << *end; 
}