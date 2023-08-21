/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pipex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:37:15 by sejkim2           #+#    #+#             */
/*   Updated: 2023/08/21 12:03:42 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	make_process(int index, t_node *node, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		child_process(index, node);
		if (node->is_heredoc == 1)
			unlink("here_doc");
		if (execve(node->path_env[index], node->cmd[index], envp) == -1)
			free_all_data(node, 1);
	}
	else
		parent_process(index, node);
}

static	void	after_make_process(t_node *node)
{
	pid_t	pid;
	int		i;

	i = 0;
	close(node->pipe_a[0]);
	close(node->pipe_a[1]);
	close(node->pipe_b[0]);
	close(node->pipe_b[1]);
	while (i < node->num_of_cmd)
	{
		pid = wait(0);
		if (pid < 0)
		{
			perror("wait:");
			free_all_data(node, 1);
		}
		i++;
	}
}

static	void	make_pipe(int index, t_node *node)
{
	if (index % 2 == 0)
	{
		if (pipe(node->pipe_a) == -1)
		{
			perror("pipe:");
			free_all_data(node, 1);
		}
	}
	else
	{
		if (pipe(node->pipe_b) == -1)
		{
			perror("pipe:");
			free_all_data(node, 1);
		}
	}
}

void	run_pipex(t_node *node, char **envp)
{
	int	index;

	index = 0;
	while (index < node->num_of_cmd)
	{
		make_pipe(index, node);
		make_process(index, node, envp);
		index++;
	}
	after_make_process(node);
}
