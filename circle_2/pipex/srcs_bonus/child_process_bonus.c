/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:49:31 by sejkim2           #+#    #+#             */
/*   Updated: 2023/08/21 12:03:34 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static	void	redirection(t_node *node, int read_dest_fd, int write_dest_fd)
{
	int	res1;
	int	res2;

	res1 = dup2(read_dest_fd, STDIN_FILENO);
	close(read_dest_fd);
	res2 = dup2(write_dest_fd, STDOUT_FILENO);
	close(write_dest_fd);
	if (res1 < 0 || res2 < 0)
		free_all_data(node, 1);
}

static	void	last_child_process(int index, t_node *node)
{
	if (index % 2 == 0)
	{
		close(node->pipe_a[0]);
		close(node->pipe_a[1]);
		close(node->pipe_b[1]);
		redirection(node, node->pipe_b[0], node->outfile_fd);
	}
	else
	{
		close(node->pipe_b[0]);
		close(node->pipe_b[1]);
		redirection(node, node->pipe_a[0], node->outfile_fd);
	}
}

static	void	middle_child_process(int index, t_node *node)
{
	if (index % 2 == 0)
	{
		close(node->pipe_a[0]);
		redirection(node, node->pipe_b[0], node->pipe_a[1]);
	}
	else
	{
		close(node->pipe_b[0]);
		redirection(node, node->pipe_a[0], node->pipe_b[1]);
	}
}

void	child_process(int index, t_node *node)
{
	if (index == 0)
	{
		close(node->pipe_a[0]);
		redirection(node, node->infile_fd, node->pipe_a[1]);
	}
	else if (index == node->num_of_cmd - 1)
		last_child_process(index, node);
	else
		middle_child_process(index, node);
}
