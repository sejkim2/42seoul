#include "../includes/pipex.h"

static char *check_cmd_is_availabe(char **path, char *input_cmd)
{
    int i = 0;
    char *cmd_with_root;
    char *cmd_with_path;

    cmd_with_root = ft_strjoin("/", input_cmd);
    while (path[i])
    {
        cmd_with_path = ft_strjoin(path[i], cmd_with_root);
        if (access(cmd_with_path, X_OK) == 0)
        {
            free(cmd_with_root);
            return (cmd_with_path);
        }
        free(cmd_with_path);
        i++;
    }
    ft_printf("%s is not available\n", input_cmd);
    free(cmd_with_root);
    return (0);
}

static int find_root(char *cmd)
{
    int i;

    i = ft_strlen(cmd);
    while (i >= 0)
    {
        if (cmd[i] == '/')
            return (i + 1);
        i--;
    }
    return (0);
}

void init_path_env(t_node *node, char **path)
{
    int i;
    int root_place;

    i = 0;
    node->path_env = (char **)malloc(sizeof(char *) * (node->num_of_cmd + 1));
    while (i < node->num_of_cmd)
    {
        if (node->cmd[i][0] == 0)
        {
            node->path_env[i] = 0;
            ft_printf("blank is not available\n");
        }
        else
        {
            root_place = find_root(node->cmd[i][0]);
            node->path_env[i] = check_cmd_is_availabe(path, node->cmd[i][0] + root_place);
            if (root_place > 0 && node->path_env[i] != 0)
            {
                if (access(node->cmd[i][0], X_OK) != 0)
                {
                    node->path_env[i] = 0;
                    ft_printf("%s is not available\n", node->cmd[i][0]);
                }
            }
        }
        i++;
    }
    node->path_env[i] = 0;
}