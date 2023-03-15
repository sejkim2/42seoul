#include "libft.h"

size_t  row_size(char const *s, char c)
{
    size_t i;
    size_t count;
    size_t len;

    len = ft_strlen(s);
    i = 0;
    count = 0;
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

void    make_split_string(char **table, const char *s, size_t head, size_t tail)
{
    size_t i;

    i = 0;
    *table = (char *)malloc(sizeof(char) * (tail - head + 1));
    while (i < tail - head)
    {
        (*table)[i] = s[i + head];
        i++;
    }
    (*table)[i] = '\0';
}

char **ft_split(char const *s, char c)
{
    char **table;
    char **first;
    size_t row;
    size_t i;
    size_t s_len;
    size_t head;

    row = row_size(s, c);
    i = 0;
    s_len = ft_strlen(s);
    table = (char **)malloc(sizeof(char *) * (row + 1));
    if (table == 0)
        return (0);
    first = table;
    while (s[i] && s[i] == c)
        i++;
    head = i;
    while (i <= s_len)
    {
        if (s[i] == '\0' || s[i] == c)
        {
            make_split_string(&(*table), s, head, i);
            while (s[i] == '\0' || s[i] == c)
                i++;
            table++;
            head = i;
        }
        else
            i++;
    }
    table = 0;
    return (first);
}

int main()
{
    char **s = ft_split(",,he,,,efe,,d,,dfaerg", ',');
    for(int i = 0; i<4; i++)
        printf("%s\n", s[i]);
}