#include "../includes/pipex.h"

static void child1_process(t_node *node, char **envp, int fd[2])
{
    close(fd[0]);
    dup2(fd[1], STDOUT_FILENO);
    dup2(node->infile_fd, STDIN_FILENO);
    close(fd[1]);
    close(node->infile_fd);
    execve(node->path_env1, node->cmd1, envp);
}

static void child2_process(t_node *node, char **envp, int fd[2])
{
    close(fd[1]);
    dup2(fd[0], STDIN_FILENO);
    dup2(node->outfile_fd, STDOUT_FILENO);
    close(fd[0]);
    close(node->outfile_fd);
    execve(node->path_env2, node->cmd2, envp);
}

void run_pipex(t_node *node, char **envp)
{
    int fd[2];
    pid_t child1;
    pid_t child2;

    pipe(fd);
    child1 = fork();
    if (child1 == -1)
        exit(1);
    else if (child1 == 0)
        child1_process(node, envp, fd);
    else
    {
        child2 = fork();
        if (child2 == -1)
            exit(1);
        else if (child2 == 0)
            child2_process(node, envp, fd);
        else
        {
            waitpid(child1, 0, 0);
            waitpid(child2, 0, 0);
        }
    }
}