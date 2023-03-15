#include "libft.h"

void *ft_calloc(size_t count, size_t size)
{
    unsigned char *p;
    size_t i;

    i = 0;
    if (size == 0 || count == 0)
    {
        p = (unsigned char *)malloc(1);
        p = 0;
    }
    else
    {
        p = (unsigned char *)malloc(size * count);
        if (p == 0)
            return (0);
        while (i < size)
            p[i++] = 0;
    }
    return (p);
}