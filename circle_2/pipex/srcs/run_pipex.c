#include "../includes/pipex.h"

// static void child1_process(t_node *node, char **envp, int fd[2])
// {
//     close(fd[0]);
//     dup2(fd[1], STDOUT_FILENO);
//     dup2(node->infile_fd, STDIN_FILENO);
//     close(fd[1]);
//     close(node->infile_fd);
//     execve(node->path_env[0], node->cmd[0], envp);
// }

// static void child2_process(t_node *node, char **envp, int fd[2])
// {
//     close(fd[1]);
//     dup2(fd[0], STDIN_FILENO);
//     dup2(node->outfile_fd, STDOUT_FILENO);
//     close(fd[0]);
//     close(node->outfile_fd);
//     execve(node->path_env[1], node->cmd[1], envp);
// }

// static void sub_dup2(int zero, int first)
// {
//     dup2(zero, STDIN_FILENO);
//     dup2(first, STDOUT_FILENO);
// }

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
        waitpid(pid, 0, 0);
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

// void run_pipex(t_node *node, char **envp)
// {
//     int fd[2];
//     pid_t child1;
//     pid_t child2;

//     pipe(fd);
//     child1 = fork();
//     if (child1 == -1)
//         exit(1);
//     else if (child1 == 0)
//         child1_process(node, envp, fd);
//     else
//     {
//         child2 = fork();
//         if (child2 == -1)
//             exit(1);
//         else if (child2 == 0)
//             child2_process(node, envp, fd);
//         else
//         {
//             close(fd[0]);
//             close(fd[1]);
//             waitpid(child1, 0, 0);
//             waitpid(child2, 0, 0);
//         }
//     }
// }