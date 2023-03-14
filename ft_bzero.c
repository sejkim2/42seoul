#include "libft.h"

void    *ft_bzero(void *b, size_t len)
{
    size_t i;
    void *p;

    p = b;
    i = 0;
    while (i < len)
    {
        *((unsigned char *)p + i) = 0;
        i++;
    }
    return (b);
}