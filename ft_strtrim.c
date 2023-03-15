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
    size_t i;
    char *dest;

    head = 0;
    tail = ft_strlen(s1) - 1;
    i = 0;
    while (isSet(s1[head], set) > -1)
        head++;
    while (isSet(s1[tail], set) > -1)
        tail--;
    dest = (char *)malloc(sizeof(char) * (tail - head + 1));
    if (dest == 0)
        return (0);
    while (i < tail - head + 1)
    {
        dest[i] = s1[head + i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}