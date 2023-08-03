#include "../includes/pipex.h"

static void child_process(t_node *node, char **envp)
{
    close(node->pipe_fd[0]);
    dup2(node->pipe_fd[1], STDOUT_FILENO);
    dup2(node->infile_fd, STDIN_FILENO);
    close(node->pipe_fd[1]);
    close(node->infile_fd);
    execve(node->path_env1, node->cmd1, envp);
}

static void parent_process(t_node *node, char **envp)
{
    close(node->pipe_fd[1]);
    dup2(node->pipe_fd[0], STDIN_FILENO);
    dup2(node->outfile_fd, STDOUT_FILENO);
    close(node->pipe_fd[0]);
    close(node->outfile_fd);
    waitpid(node->pid, 0, 0);
    execve(node->path_env2, node->cmd2, envp);
}

void run_pipex(t_node *node, char **envp)
{
    pipe(node->pipe_fd);
    node->pid = fork();
    if (node->pid == -1)
        exit(1);
    else if (node->pid == 0)
        child_process(node, envp);
    else
        parent_process(node, envp);
}