/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:32:51 by sejkim2           #+#    #+#             */
/*   Updated: 2023/08/01 15:49:06 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void parsing_cmd_and_filename(char **argv, t_node *node)
{
    node->infile_name = argv[1];
    node->cmd1 = argv[2];
    node->cmd2 = argv[3];
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

static void check_cmd_is_availabe(t_node *node, char **envp)
{
    int i = 0;

    node->path_env = find_path_in_envp_and_split(envp);
    if (node->path_env == 0)
    {
        ft_printf("$PATH is not exist\n");
        exit(1);
    }
    while (node->path_env[i])
    {
        if (access(node->path_env[i], X_OK) == -1)
        {
            ft_printf("%s is not available\n", node->path_env[i]);
            exit(1);
        }
        i++;
    }
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
    check_cmd_is_availabe(&node, envp);
    run_pipex(&node);
}