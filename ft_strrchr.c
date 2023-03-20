#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
    size_t i;
    size_t len;
    char *p;
    char *result;

    p = (char *)s;
    result = 0;
    i = 0;
    len = ft_strlen(s);
    while (i <= len)
    {
        if (*(p + i) == (char)c)
            result = p + i;
        i++;
    }
    return (result);
}