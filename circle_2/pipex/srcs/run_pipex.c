#include "../includes/pipex.h"

static void parent_process(t_node *node, int fd[2])
{
    
}

static void child_process(t_node *node, int fd[2])
{

}

void run_pipex(t_node *node)
{
    pid_t pid;
    int fd[2];

    if (pipe(fd) < 0)
    {
        ft_printf("pipe error\n");
        exit(1);
    }
    pid = fork();
    if (pid == -1)
    {
        ft_printf("fork error\n");
        exit(1);
    }
    else if (pid == 0)
        child_process(node, fd);
    else
        parent_process(node, fd);
}