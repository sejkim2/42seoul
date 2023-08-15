/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:32:51 by sejkim2           #+#    #+#             */
/*   Updated: 2023/08/15 15:50:41 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void open_infile_and_outfile(int argc, char **argv, t_node *node)
{
    node->infile_fd = open(argv[1], O_RDONLY | O_CREAT, 0644);
    if (node->is_heredoc == 0)
        node->outfile_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    else
        node->outfile_fd = open(argv[argc - 1], O_WRONLY | O_APPEND, 0644);
    if (node->infile_fd == -1)
    {
        ft_printf("infile open error\n");
        exit(1);
    }
    if (node->outfile_fd == -1)
    {
        ft_printf("outfile open error\n");
        exit(1);
    }
}

static char **find_path_in_envp_and_split(char **envp)
{
    int i;
    int flag;
    char *p;

    i = 0;
    flag = 0;
    while (envp[i])
    {
        p = ft_strnstr(envp[i], "PATH=", 5);
        if (p != 0)
        {
            flag = 1;
            break;
        }
        else
            i++;
    }
    if (flag == 0)
        return (0);
    return (ft_split(p + 5, ':'));
}

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

static void init_path_env(t_node *node, char **path)
{
    int i;

    i = 0;
    node->path_env = (char **)malloc(sizeof(char *) * (node->num_of_cmd));
    while (i < node->num_of_cmd)
    {
        node->path_env[i] = check_cmd_is_availabe(path, node->cmd[i][0]);
        i++;
    }
}

int main(int argc, char **argv, char **envp)
{
    t_node node;
    char **path;

    if (argc < 5)
    {
        ft_printf("argument error\n");
        exit(1);
    }
    parsing_cmd_and_filename(argc, argv, &node);
    open_infile_and_outfile(argc, argv, &node);
    path = find_path_in_envp_and_split(envp);
    if (path == 0)
    {
        ft_printf("$PATH is not exist\n");
        exit(1);
    }
    init_path_env(&node, path);
    run_pipex(&node, envp);
    return (0);
}
