#include "../includes/pipex.h"

static void child_process(t_node *node, int pipe_fd[2])
{
    close(pipe_fd[0]);
    dup2(pipe_fd[1], STDOUT_FILENO);
    dup2(node->fd[0], STDIN_FILENO);
    // close(node->fd[0]);
    execve(node->path_env1, node->cmd1, 0);
}

static void parent_process(pid_t pid, t_node *node, int pipe_fd[2])
{
    close(pipe_fd[1]);
    dup2(pipe_fd[0], STDIN_FILENO);
    dup2(node->fd[1], STDOUT_FILENO);
    // close(node->fd[1]);
    waitpid(pid, 0, 0);
    execve(node->path_env2, node->cmd2, 0);
}

void run_pipex(t_node *node)
{
    pid_t pid;
    int pipe_fd[2];

    if (pipe(pipe_fd) < 0)
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
        child_process(node, pipe_fd);
    else
        parent_process(pid, node, pipe_fd);
}