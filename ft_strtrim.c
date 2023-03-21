#include "libft.h"

int isSet(char ch, char const *set)
{
    size_t i;

    i = 0;
    while (set[i])
    {
        if (ch == set[i])
            return (i);
        else
            i++;
    }
    return (-1);
}

char *ft_strtrim(char const *s1, char const *set)
{
    size_t head;
    size_t tail;
    size_t s1_len;
    char *dest;

    if (s1 == 0)
    {
        dest = malloc(1);
        *dest = '\0';
        return (0);
    }
    s1_len = ft_strlen(s1);
    head = 0;
    tail = s1_len - 1;
    while (head < s1_len && isSet(s1[head], set) > -1)
        head++;
    while (tail > head && isSet(s1[tail], set) > -1)
        tail--;
    dest = (char *)malloc(sizeof(char) * (tail - head + 2));
    if (dest == 0)
        return (0);
    ft_strlcpy(dest, s1 + head, tail - head + 1);
    return (dest);
}