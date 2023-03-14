char *ft_strrchr(const char *s, int c)
{
    char *p;
    char *result;

    p = (char *)s;
    result = 0;
    while (*p)
    {
        if (*p == c)
            result = p;
        else
            p++;
    }
    return (result);
}