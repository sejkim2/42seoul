#include "libft.h"

void *ft_calloc(size_t count, size_t size)
{
    unsigned char *p;
    size_t i;

    i = 0;
    if (size == 0 || count == 0)
    {
        p = (unsigned char *)malloc(1);
        if (p == 0)
            return (0);
        p[i] = 0;
    }
    else
    {
        p = (unsigned char *)malloc(size * count);
        if (p == 0)
            return (0);
        while (i < count * size)
            p[i++] = 0;
    }
    return (p);
}