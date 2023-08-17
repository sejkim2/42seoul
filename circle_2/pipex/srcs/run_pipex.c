#include "../includes/pipex.h"

static void child_process(int index, t_node *node, char **envp, int pipe_A[2], int pipe_B[2])
{
    pid_t pid;

    pid = fork();
    if (pid == 0)
    {
        if (index == 0)
        {
            close(pipe_A[0]);

            dup2(node->infile_fd, STDIN_FILENO);
            close(node->infile_fd);
            dup2(pipe_A[1], STDOUT_FILENO);
            close(pipe_A[1]);
        }
        else if (index == node->num_of_cmd - 1)
        {
            if (index % 2 == 0)
            {
                close(pipe_B[1]);

                close(pipe_A[0]);
                close(pipe_A[1]);

                dup2(pipe_B[0], STDIN_FILENO);
                close(pipe_B[0]);
                dup2(node->outfile_fd, STDOUT_FILENO);
                close(node->outfile_fd);
            }
            else
            {
                close(pipe_A[1]);

                close(pipe_B[0]);
                close(pipe_B[1]);

                dup2(pipe_A[0], STDIN_FILENO);
                close(pipe_A[0]);
                dup2(node->outfile_fd, STDOUT_FILENO);
                close(node->outfile_fd);
            }
        }
        else
        {
            if (index % 2 == 0)
            {
                close(pipe_B[1]);

                close(pipe_A[0]);

                dup2(pipe_B[0], STDIN_FILENO);
                close(pipe_B[0]);
                dup2(pipe_A[1], STDOUT_FILENO);
                close(pipe_A[1]);
            }
            else
            {
                close(pipe_A[1]);

                close(pipe_B[0]);
                
                dup2(pipe_A[0], STDIN_FILENO);
                close(pipe_A[0]);
                dup2(pipe_B[1], STDOUT_FILENO);
                close(pipe_B[1]);
            }
        }
        if (execve(node->path_env[index], node->cmd[index], envp) == -1)
        {

        }
    }
    else
    {
        if (index == 0)
        {
            close(pipe_A[1]);
        }
        else if (index == node->num_of_cmd - 1)
        {
            if (index % 2 == 0)
            {
                close(pipe_B[0]);
                close(pipe_A[1]);
            }
            else
            {
                close(pipe_A[0]);
                close(pipe_B[1]);
            }
        }
        else
        {
            if (index % 2 == 0)
            {
                close(pipe_B[0]);
                close(pipe_A[1]);
            }
            else
            {
                close(pipe_A[0]);
                close(pipe_B[1]);
            }
        }
    }
}

void run_pipex(t_node *node, char **envp)
{
    int pipe_A[2];
    int pipe_B[2];
    int index;
    int i;

    index = 0;
    i = 0;
    while (index < node->num_of_cmd)
    {
        if (index % 2 == 0)
            pipe(pipe_A);
        else
            pipe(pipe_B);
        child_process(index, node, envp, pipe_A, pipe_B);
        index++;
    }
    close(pipe_A[0]);
    close(pipe_A[1]);
    close(pipe_B[0]);
    close(pipe_B[1]);
    while (i < node->num_of_cmd)
    {
        wait(0);
        i++;
    }
    if (node->is_heredoc == 1)
        unlink("here_doc");
}