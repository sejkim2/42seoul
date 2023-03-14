#include "libft.h"

void    *ft_memmove(void *dst, const void *src, size_t len)
{
    size_t i;
    void *p;

    i = 0;
    p = dst;

    if (dst < src)
    {
        while (i < len)
        {
            *((unsigned char *)p + i) = *((unsigned char *)src + i);
            i++;
        }
    }
    else
    {
        p = p + len;
        while (i < len)
        {
            *((unsigned char *)p - i) = *((unsigned char *)src - i);
            i++;
        }
    }
    return (dst);
}