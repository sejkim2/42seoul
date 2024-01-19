#include <stdio.h>
#include <stdlib.h>

int *init_ar(int n)
{
    int *ar = malloc(sizeof(int) * n);
    for(int i = 0; i<n; i++)
        ar[i] = i;
    return ar;
}

int main()
{
    int n = 4;
    int *ar = init_ar(n);
    for(int i = 0; i<n; i++)
        printf("%d ", ar[i]);
}