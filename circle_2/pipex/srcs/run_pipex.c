#include "../includes/pipex.h"

static void child_process(int index, t_node *node, char **envp)
{
    pid_t pid;
    int fd[2];

    pipe(fd);
    pid = fork();
    if (pid == 0)
    {
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        execve(node->path_env[index], node->cmd[index], envp);
    }
    else
    {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        waitpid(pid, 0, WNOHANG);
    }
}

void run_pipex(t_node *node, char **envp)
{
    int index;

    index = 0;
    dup2(node->infile_fd, STDIN_FILENO);
    close(node->infile_fd);

    while (index < node->num_of_cmd)
    {
        child_process(index, node, envp);
        index++;
    }
    dup2(node->outfile_fd, STDOUT_FILENO);
    close(node->outfile_fd);
    execve(node->path_env[index - 1], node->cmd[index - 1], envp);
}
