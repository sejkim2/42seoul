#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *dest;
    size_t s_len;
    size_t i;

    dest = (char *)malloc(sizeof(char) * (len + 1));
    if (dest == 0)
        return (0);
    s_len = ft_strlen(s);
    i = 0;
    while (i < len && start + i < s_len && s[start + i])
    {
        dest[i] = s[start + i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}