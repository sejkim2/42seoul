#include "../includes/pipex.h"

void run_pipex(t_node *node, char **envp)
{
    if (pipe(node->pipe_fd) < 0)
    {
        ft_printf("pipe error\n");
        exit(1);
    }
    node->pid = fork();
    if (node->pid == -1)
    {
        ft_printf("fork error\n");
        exit(1);
    }
    else if (node->pid == 0)
    {
        close(node->pipe_fd[0]);
        dup2(node->pipe_fd[1], STDOUT_FILENO);
        dup2(node->infile_fd, STDIN_FILENO);
        close(node->pipe_fd[1]);
        close(node->infile_fd);
        execve(node->path_env1, node->cmd1, envp);
    }
    else
    {
        close(node->pipe_fd[1]);
        dup2(node->pipe_fd[0], STDIN_FILENO);
        dup2(node->outfile_fd, STDOUT_FILENO);
        close(node->pipe_fd[0]);
        close(node->outfile_fd);
        waitpid(node->pid, 0, 0);
        execve(node->path_env2, node->cmd2, envp);
    }
}