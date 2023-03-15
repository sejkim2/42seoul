#include "libft.h"

int len_num(const int n)
{
    int isMinus;
    int len;
    long long num;

    if (n < 0)
    {
        isMinus = 1;
        num = (long long)(-1) * n;
    }
    else
    {
        isMinus = 0;
        num = n;
    }
    len = 0;
    while (num > 0)
    {
        num = num / 10;
        len++;
    }
    return (len + isMinus);
}

char    *num_to_string(char *dest, int n, int len)
{
    long long num;
    int i;

    i = len;
    dest[i--] = '\0';
    num = (long long)n;
    if (num == 0)
    {
        dest[0] = '0';
        return (dest);
    }
    else if (num < 0)
    {
        dest[0] = '-';
        num = (-1) * num;
    }
    while (num > 0)
    {
        dest[i--] = num % 10 + '0';
        num = num / 10;
    }
    return (dest);
}

char *ft_itoa(int n)
{
    char *dest;
    int len;

    len = len_num(n);
    dest = (char *)malloc(sizeof(char) * (len + 1));
    if (dest == 0)
        return (0);
    dest = num_to_string(dest, n, len);
    return (dest);
}