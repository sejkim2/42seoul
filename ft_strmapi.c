#include "libft.h"

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    size_t len;
    unsigned int i;
    char *dest;

    len = ft_strlen(s);
    i = 0;
    dest = (char *)malloc(sizeof(char) * (len + 1));
    if (dest == 0)
        return (0);
    while (s[i])
    {
        dest[i] = f(i, s[i]);
        i++;
    }
    return (dest);
}