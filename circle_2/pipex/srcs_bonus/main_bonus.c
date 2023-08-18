/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:32:51 by sejkim2           #+#    #+#             */
/*   Updated: 2023/08/18 17:01:08 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static	void	open_infile_and_outfile(int argc, char **argv, t_node *node)
{
	node->infile_fd = open(argv[1], O_RDONLY, 0644);
	if (node->infile_fd == -1)
		ft_printf("pipex: no such file or directory: %s\n", argv[1]);
	if (node->is_heredoc == 0)
		node->outfile_fd = open(argv[argc - 1], \
		O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		node->outfile_fd = open(argv[argc - 1], \
		O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (node->outfile_fd == -1)
	{
		perror("outfile:");
		close(node->infile_fd);
		free_cmd(node, node->num_of_cmd);
		exit(1);
	}
}

static	char	**find_path_in_envp_and_split(char **envp)
{
	int		i;
	int		flag;
	char	*p;

	i = 0;
	flag = 0;
	while (envp[i])
	{
		p = ft_strnstr(envp[i], "PATH=", 5);
		if (p != 0)
		{
			flag = 1;
			break ;
		}
		else
			i++;
	}
	if (flag == 0)
		return (0);
	return (ft_split(p + 5, ':'));
}

int	main(int argc, char **argv, char **envp)
{
	t_node	node;
	char	**path;

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
		free_cmd(&node, node.num_of_cmd);
		exit(1);
	}
	init_path_env(&node, path);
	free_path(path);
	run_pipex(&node, envp);
	free_all_data(&node, 0);
	if (node.is_error == 1)
		exit(1);
	return (0);
}
