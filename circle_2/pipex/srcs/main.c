/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:32:51 by sejkim2           #+#    #+#             */
/*   Updated: 2023/08/02 16:47:23 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void parsing_cmd_and_filename(char **argv, t_node *node)
{
    node->infile_name = argv[1];
    node->cmd1 = ft_split(argv[2], ' ');
    node->cmd2 = ft_split(argv[3], ' ');
    node->outfile_name = argv[4];
}

static void check_file_is_accessable(t_node *node)
{
    if (access(node->infile_name, F_OK) == -1)
    {
        ft_printf("%s is not exist\n", node->infile_name);
        exit(1);
    }
    if (access(node->infile_name, R_OK) == -1)
    {
        ft_printf("%s is not readable", node->infile_name);
        exit(1);
    }
    if (access(node->infile_name, W_OK) == -1)
    {
        ft_printf("%s is not writable", node->infile_name);
        exit(1);
    }
    if (access(node->outfile_name, F_OK) == -1)
    {
        ft_printf("%s is not exist\n", node->outfile_name);
        exit(1);
    }
    if (access(node->outfile_name, R_OK) == -1)
    {
        ft_printf("%s is not readable", node->outfile_name);
        exit(1);
    }
    if (access(node->outfile_name, W_OK) == -1)
    {
        ft_printf("%s is not writable", node->outfile_name);
        exit(1);
    }
    node->fd[0] = open(node->infile_name, O_WRONLY);
    node->fd[1] = open(node->outfile_name, O_WRONLY);
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

static int check_cmd_is_availabe(char **envp, char *input_cmd, char **path_env_cmd)
{
    int i = 0;
    char *cmd_with_root;
    char *cmd_with_path;
    char **path_env;

    path_env = find_path_in_envp_and_split(envp);

    if (path_env == 0)
    {
        ft_printf("$PATH is not exist\n");
        exit(1);
    }
    cmd_with_root = ft_strjoin("/", input_cmd);   //   /ls
    while (path_env[i])
    {
        cmd_with_path = ft_strjoin(path_env[i], cmd_with_root);   //  path/ls
        if (access(cmd_with_path, X_OK) == 0)
        {
            *path_env_cmd = cmd_with_path;
            free(cmd_with_root);
            free(cmd_with_path);
            return (1);
        }
        free(cmd_with_path);
        i++;
    }
    ft_printf("%s is not available\n", input_cmd);
    free(cmd_with_root);
    return (0);
}

int main(int argc, char **argv, char **envp)
{
    t_node node;

    if (argc != 5)
    {
        ft_printf("argument error\n");
        exit(1);
    }
    if (envp == 0)
        exit(1);
    parsing_cmd_and_filename(argv, &node);
    check_file_is_accessable(&node);
    if (check_cmd_is_availabe(envp, node.cmd1[0], &(node.path_env1)) == 0)
        exit(1);
    if (check_cmd_is_availabe(envp, node.cmd2[0], &(node.path_env2)) == 0)
        exit(1);
    run_pipex(&node);
}