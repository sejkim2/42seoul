#include "libft.h"

size_t  row_size(char const *s, char c)
{
    size_t i;
    size_t count;
    size_t len;

    len = ft_strlen(s);
    i = 0;
    count = 1;
    while (s[i] == c || s[i] == '\0')
        i++;
    while (i <= len)
    {
        if (s[i] == c || s[i] == '\0')
        {
            while (s[i] == c || s[i] == '\0')
                i++;
            count++;
        }
        else
            i++;
    }
    return (count);
}

char **ft_split(char const *s, char c)
{
    char **table;
    size_t row;
    size_t i;

    row = row_size(s, c);
    i = 0;
    table = (char **)malloc(sizeof(char *) * (row));
    if (table == 0)
        return (0);
    
    
}