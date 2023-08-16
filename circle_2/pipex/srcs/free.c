#include "../includes/pipex.h"

static int check_string_length(char **str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

static void free_cmd(t_node *node)
{
    int i;
    int j;
    int len;

    i = 0;
    while (i < node->num_of_cmd)
    {
        j = 0;
        len = check_string_length(node->cmd[i]);
        while (j < len)
        {
            free(node->cmd[i][j]);
            j++;
        }
        if (j > 0)
            free(node->cmd[i]);
        i++;
    }
    if (i > 0)
        free(node->cmd);
}

static void free_two_pointer(char **path)
{
    int i;
    
    i = 0;
    while (path[i])
    {
        free(path[i]);
        i++;
    }
    if (i > 0)
        free(path);
}

void free_all_data(char **path, t_node *node)
{
    free_cmd(node);
    free_two_pointer(path);
    free_two_pointer(node->path_env);
}