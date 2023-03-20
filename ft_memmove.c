#include "libft.h"

void    *ft_memmove(void *dst, const void *src, size_t len)
{
    size_t i;

    if (dst == src)
        return (dst);
    if (dst < src)
        dst = ft_memcpy(dst, src, len);
    else
    {
        i = len;
        while (i-- > 0)
            *((unsigned char *)dst + i) = *((unsigned char *)src + i);
    }
    return (dst);
}