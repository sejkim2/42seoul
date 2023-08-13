/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:32:51 by sejkim2           #+#    #+#             */
/*   Updated: 2023/08/07 18:04:57 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void parsing_cmd_and_filename(int argc, char **argv, t_node *node)
{
    int i;

    i = 0;
    node->infile_name = argv[1];
    node->cmd = (char ***)malloc(sizeof(char **) * (node->num_of_cmd));
    while (i < node->num_of_cmd)
    {
        node->cmd[i] = ft_split(argv[i + 2], ' ');
        i++;
    }
    node->outfile_name = argv[argc - 1];
}

static void check_file_is_openable(t_node *node)
{
    node->infile_fd = open(node->infile_name, O_RDONLY, 0644);
    node->outfile_fd = open(node->outfile_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
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

    cmd_with_root = ft_strjoin("/", input_cmd);   //   /ls
    while (path[i])
    {
        cmd_with_path = ft_strjoin(path[i], cmd_with_root);   //  path/ls
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

    // if (argc != 5)
    // {
    //     ft_printf("argument error\n");
    //     exit(1);
    // }
    if (envp == 0)
        exit(1);
    node.num_of_cmd = argc - 3;
    parsing_cmd_and_filename(argc, argv, &node);
    check_file_is_openable(&node);
    path = find_path_in_envp_and_split(envp);
    if (path == 0)
    {
        ft_printf("$PATH is not exist\n");
        exit(1);
    }
    init_path_env(&node, path);
    run_pipex(&node, envp);
}