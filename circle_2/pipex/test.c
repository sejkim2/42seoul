#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    int fd[2];
    pid_t pid;

    pipe(fd);
    pid = fork();
    if (pid == 0)
        printf("child\n");
    else printf("parent\n");
}