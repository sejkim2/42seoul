#include "libft.h"

void    *ft_memset(void *b, int c, size_t len)
{
    size_t i;
    void *p;
    
    i = 0;
    p = b;
    while (i < len)
    {
        *((unsigned char *)p + i) = (unsigned char)c;
        i++;
    }
    return (b);
}