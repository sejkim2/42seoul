/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cmd_and_filename.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:00:17 by sejkim2           #+#    #+#             */
/*   Updated: 2023/08/18 15:03:59 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static	void	run_heredoc(char *limiter)
{
	char	*str;
	int		heredoc_fd;
	size_t	len;

	heredoc_fd = open("here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	len = ft_strlen(limiter);
	while (1)
	{
		ft_printf("pipe heredoc> ");
		str = get_next_line(0);
		if (str == 0)
			break ;
		if (ft_strlen(str) - 1 == len && ft_strncmp(str, limiter, len) == 0)
		{
			free(str);
			break ;
		}
		write(heredoc_fd, str, ft_strlen(str));
		free(str);
	}
	close(heredoc_fd);
}

static	void	check_is_heredoc(int argc, char **argv, t_node *node)
{
	if (ft_strlen(argv[1]) == 8 && ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		node->is_heredoc = 1;
		node->num_of_cmd = argc - 4;
		run_heredoc(argv[2]);
	}
	else
	{
		node->is_heredoc = 0;
		node->num_of_cmd = argc - 3;
	}
}

void	parsing_cmd_and_check_heredoc(int argc, char **argv, t_node *node)
{
	int	i;

	i = 0;
	check_is_heredoc(argc, argv, node);
	node->cmd = (char ***)malloc(sizeof(char **) * (node->num_of_cmd));
	if (node->cmd == 0)
	{
		ft_printf("malloc error\n");
		exit(1);
	}
	while (i < node->num_of_cmd)
	{
		node->cmd[i] = ft_split(argv[i + 2 + node->is_heredoc], ' ');
		if (node->cmd[i] == 0)
		{
			ft_printf("malloc error");
			free_cmd(node, i);
			exit(1);
		}
		i++;
	}
}
