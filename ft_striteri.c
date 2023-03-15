#include "libft.h"

void ft_striteri(char *s, void (*f)(unsigned int, char*))
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
        f(i, s + i);
        i++;
    }
    return (dest);
}