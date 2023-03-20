#include "libft.h"

char *ft_strchr(const char *s, int c)
{
    char *p;
    size_t i;
    size_t len;

    p = (char *)s;
    i = 0;
    len = ft_strlen(s);
    while (i <= len)
    {
        if (*(p + i) == (char)c)
            return (p + i);
        else
            i++;
    }
    return (0);
}