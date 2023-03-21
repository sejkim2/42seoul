#include "libft.h"

void    ft_putstr_fd(char *s, int fd)
{
    while (*s)
        write(1, s++, fd);
    // size_t i;
    // i = 0;
    // while (s[i])
    // {
    //     ft_putchar_fd(s[i], fd);
    //     i++;
    // }
}

// #include <fcntl.h>

// int main()
// {
//     int fd = open("./test.txt", O_WRONLY | O_CREAT, 0644);
//     ft_putstr_fd("hello", fd);
//     close(fd);
// }