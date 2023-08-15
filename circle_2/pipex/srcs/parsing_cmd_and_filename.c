/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cmd_and_filename.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:00:17 by sejkim2           #+#    #+#             */
/*   Updated: 2023/08/15 14:00:19 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void run_heredoc(t_node *node, char *limiter)
{
    char *str;
    int heredoc_fd;
    size_t len;
    int i;

    heredoc_fd = open("here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    len = ft_strlen(limiter);
    while (1)
    {
        i = 0;
        while (i < node->num_of_cmd - 1)
        {
            ft_printf("pipe ");
            i++;
        }
        ft_printf("heredoc> ");
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

void parsing_cmd_and_filename(int argc, char **argv, t_node *node)
{
    int i;

    i = 0;
    node->is_heredoc = 0;
    if (ft_strncmp(argv[1], "here_doc", 8) == 0)
    {
        node->num_of_cmd = argc - 4;    
        run_heredoc(node, argv[2]);
    }
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