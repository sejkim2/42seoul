#include "../includes/pipex.h"

static void child1_process(t_node *node, char **envp, int fd[2])
{
    close(fd[0]);
    dup2(fd[1], STDOUT_FILENO);
    dup2(node->infile_fd, STDIN_FILENO);
    close(fd[1]);
    close(node->infile_fd);
    execve(node->path_env[0], node->cmd[0], envp);
}

static void child2_process(t_node *node, char **envp, int fd[2])
{
    close(fd[1]);
    dup2(fd[0], STDIN_FILENO);
    dup2(node->outfile_fd, STDOUT_FILENO);
    close(fd[0]);
    close(node->outfile_fd);
    execve(node->path_env[1], node->cmd[1], envp);
}

void run_pipex(t_node *node, char **envp)
{
    int i;
    int **pipe_fd;

    i = 0;
    pipe_fd = (int **)malloc(sizeof(int *) * (node->num_of_cmd));
    while (i < node->num_of_cmd)
    {
        pipe_fd[i] = (int *)malloc(sizeof(int) * 2);
        pipe(pipe_fd[i]);
        i++;
    }
    // int fd[2];
    // pid_t child1;
    // pid_t child2;

    // pipe(fd);
    // child1 = fork();
    // if (child1 == -1)
    //     exit(1);
    // else if (child1 == 0)
    //     child1_process(node, envp, fd);
    // else
    // {
    //     child2 = fork();
    //     if (child2 == -1)
    //         exit(1);
    //     else if (child2 == 0)
    //         child2_process(node, envp, fd);
    //     else
    //     {
    //         close(fd[0]);
    //         close(fd[1]);
    //         waitpid(child1, 0, 0);
    //         waitpid(child2, 0, 0);
    //     }
    // }
}