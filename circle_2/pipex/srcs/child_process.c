#include "../includes/pipex.h"

static void redirection(int read_dest_fd, int write_dest_fd)
{
    dup2(read_dest_fd, STDIN_FILENO);
    close(read_dest_fd);
    dup2(write_dest_fd, STDOUT_FILENO);
    close(write_dest_fd);
}

static void last_child_process(int index, t_node *node)
{
    if (index % 2 == 0)
    {
        close(node->pipe_A[0]);
        close(node->pipe_A[1]);
        close(node->pipe_B[1]);
        redirection(node->pipe_B[0], node->outfile_fd);
    }
    else
    {
        close(node->pipe_B[0]);
        close(node->pipe_B[1]);
        redirection(node->pipe_A[0], node->outfile_fd);
    }
}

static void middle_child_process(int index, t_node *node)
{
    if (index % 2 == 0)
    {
        close(node->pipe_A[0]);
        redirection(node->pipe_B[0], node->pipe_A[1]);
    }
    else
    {
        close(node->pipe_B[0]);
        redirection(node->pipe_A[0], node->pipe_B[1]);
    }
}

void child_process(int index, t_node *node)
{
    if (index == 0)
    {
        close(node->pipe_A[0]);
        redirection(node->infile_fd, node->pipe_A[1]);
    }
    else if (index == node->num_of_cmd - 1)
        last_child_process(index, node);
    else
        middle_child_process(index, node);
}