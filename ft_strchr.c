char *ft_strchr(const char *s, int c)
{
    char *p;

    p = (char *)s;
    while (*p)
    {
        if (*p == c)
            return (p);
        else
            p++;
    }
    return (0);
}