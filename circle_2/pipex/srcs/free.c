/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:37:10 by sejkim2           #+#    #+#             */
/*   Updated: 2023/08/18 12:11:52 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static	int	check_string_length(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	free_cmd(t_node *node, int str_len)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (i < str_len)
	{
		j = 0;
		len = check_string_length(node->cmd[i]);
		while (j < len)
		{
			free(node->cmd[i][j]);
			j++;
		}
		if (j > 0)
			free(node->cmd[i]);
		i++;
	}
	if (i > 0)
		free(node->cmd);
}

void	free_path(char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	if (i > 0)
		free(path);
}

void	free_all_data(t_node *node, int error_num)
{
	int	i;

	i = 0;
	while (i <= node->num_of_cmd)
	{
		free(node->path_env[i]);
		i++;
	}
	if (i > 0)
		free(node->path_env);
	free_cmd(node, node->num_of_cmd);
	if (error_num == 1)
		exit(1);
}
