/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:56:01 by sejkim2           #+#    #+#             */
/*   Updated: 2023/08/21 12:03:09 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static	void	last_parent_process(int index, t_node *node)
{
	if (index % 2 == 0)
	{
		close(node->pipe_a[0]);
		close(node->pipe_a[1]);
		close(node->pipe_b[0]);
	}
	else
	{
		close(node->pipe_b[0]);
		close(node->pipe_b[1]);
		close(node->pipe_a[0]);
	}
}

static	void	middle_parent_process(int index, t_node *node)
{
	if (index % 2 == 0)
	{
		close(node->pipe_a[1]);
		close(node->pipe_b[0]);
	}
	else
	{
		close(node->pipe_a[0]);
		close(node->pipe_b[1]);
	}
}

void	parent_process(int index, t_node *node)
{
	if (index == 0)
		close(node->pipe_a[1]);
	else if (index == node->num_of_cmd - 1)
		last_parent_process(index, node);
	else
		middle_parent_process(index, node);
}
