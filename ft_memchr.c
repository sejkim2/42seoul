#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
    unsigned char *p;
    unsigned char ch;
    size_t i;

    p = (unsigned char *)s;
    ch = (unsigned char)c;
    i = 0;
    while (i < n)
    {
        if (*(p + i) == ch)
            return (p + i);
        else
            i++;
    }
    return (0);
}