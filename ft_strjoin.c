#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t s1_len;
    size_t s2_len;
    char *dest;

    s1_len = ft_strlen(s1);
    s2_len = ft_strlen(s2);
    dest = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
    if (dest == 0)
        return (0);
    ft_strlcpy(dest, s1, s1_len + 1);
    ft_strlcat(dest, s2, s1_len + s2_len + 1);
    return (dest);
}