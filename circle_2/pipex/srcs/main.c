/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:32:51 by sejkim2           #+#    #+#             */
/*   Updated: 2023/08/14 20:19:00 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void run_heredoc(t_node *node, char *limiter)
{
    char *str;
    int heredoc_fd;
    size_t len;

    heredoc_fd = open("here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    len = ft_strlen(limiter);
    while (1)
    {
        ft_printf("pipe heredoc> ");
        str = get_next_line(0);
        if (str == 0)
            break;
        if (ft_strlen(str) - 1 == len && ft_strncmp(str, limiter, len) == 0)
            break;
        write(heredoc_fd, str, ft_strlen(str));
    }
    close(heredoc_fd);
    node->is_heredoc = 1;
}

static void parsing_cmd_and_filename(int argc, char **argv, t_node *node)
{
    int i;

    i = 0;
    node->is_heredoc = 0;
    if (ft_strncmp(argv[1], "here_doc", 8) == 0)
        run_heredoc(node, argv[2]);
    node->infile_name = argv[1];
    node->num_of_cmd = argc - 3 - node->is_heredoc;
    node->cmd = (char ***)malloc(sizeof(char **) * (node->num_of_cmd));
    while (i < node->num_of_cmd)
    {
        node->cmd[i] = ft_split(argv[i + 2 + node->is_heredoc], ' ');
        i++;
    }
    node->outfile_name = argv[argc - 1];
}

static void check_file_is_openable(t_node *node)
{
    node->infile_fd = open(node->infile_name, O_RDONLY, 0644);
    if (node->is_heredoc == 0)
        node->outfile_fd = open(node->outfile_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    else
        node->outfile_fd = open(node->outfile_name, O_WRONLY | O_APPEND, 0644);
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