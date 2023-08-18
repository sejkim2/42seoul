#include "../includes/pipex.h"

static void last_parent_process(int index, t_node *node)
{
    if (index % 2 == 0)
    {
        close(node->pipe_A[0]);
        close(node->pipe_A[1]);
        close(node->pipe_B[0]);
    }
    else
    {
        close(node->pipe_B[0]);
        close(node->pipe_B[1]);
        close(node->pipe_A[0]);
    }
}

static void middle_parent_process(int index, t_node *node)
{
    if (index % 2 == 0)
    {
        close(node->pipe_A[1]);
        close(node->pipe_B[0]);
    }
    else
    {
        close(node->pipe_A[0]);
        close(node->pipe_B[1]);
    }
}

void parent_process(int index, t_node *node)
{
    if (index == 0)
        close(node->pipe_A[1]);
    else if (index == node->num_of_cmd - 1)
        last_parent_process(index, node);
    else
        middle_parent_process(index, node);
}