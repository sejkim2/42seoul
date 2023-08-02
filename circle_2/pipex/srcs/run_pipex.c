#include "../includes/pipex.h"

static void parent_process(t_node *node)
{
    
}

static void child_process(t_node *node)
{
    char buf[4096];
    int read_size;

    close(fd[0]);
    dup2(fd[1], STDOUT_FILENO);
    dup2(node->fd[0], STDIN_FILENO);
    close(node->fd[0]);
    read(STDIN_FILENO, buf, 100);
    write(STDOUT_FILENO, buf, 100);
}

void run_pipex(t_node *node)
{
    pid_t pid;

    if (pipe(node->fd) < 0)
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
    // child_process(node, fd);
    else if (pid == 0)
    {
        
    }
    // parent_process(node, fd);
    else
    {

    }
}