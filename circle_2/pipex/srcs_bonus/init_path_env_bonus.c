/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_path_env_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:54:15 by sejkim2           #+#    #+#             */
/*   Updated: 2023/08/21 12:03:37 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static	char	*check_cmd_is_availabe(char **path, char *input_cmd)
{
	int		i;
	char	*cmd_with_root;
	char	*cmd_with_path;

	i = 0;
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
	ft_printf("pipex: command not found: %s\n", input_cmd);
	free(cmd_with_root);
	return (0);
}

static	int	find_root(char *cmd)
{
	int	i;

	i = ft_strlen(cmd);
	while (i >= 0)
	{
		if (cmd[i] == '/')
			return (i + 1);
		i--;
	}
	return (0);
}

static	void	malloc_error(t_node *node, char **path)
{
	ft_printf("malloc error\n");
	free_path(path);
	free_cmd(node, node->num_of_cmd);
	exit(1);
}

static	void	init_path_env_utils(t_node *node, char **path, int i)
{
	int	root_place;

	root_place = find_root(node->cmd[i][0]);
	if (root_place > 0)
	{
		if (access(node->cmd[i][0], X_OK) != 0)
		{
			node->path_env[i] = 0;
			ft_printf("pipex: %s: %s\n", strerror(errno), node->cmd[i][0]);
			if (i == node->num_of_cmd - 1)
				node->is_error = 1;
		}
		else
			node->path_env[i] = ft_strdup(node->cmd[i][0]);
	}
	else
	{
		node->path_env[i] = check_cmd_is_availabe(path, \
		node->cmd[i][0] + root_place);
		if (node->path_env[i] == 0 && i == node->num_of_cmd - 1)
			node->is_error = 1;
	}
}

void	init_path_env(t_node *node, char **path)
{
	int	i;

	i = 0;
	node->path_env = (char **)malloc(sizeof(char *) * (node->num_of_cmd + 1));
	if (node->path_env == 0)
		malloc_error(node, path);
	node->is_error = 0;
	while (i < node->num_of_cmd)
	{
		if (node->cmd[i][0] == 0)
		{
			node->path_env[i] = 0;
			ft_printf("pipex: permission denied:\n");
			if (i == node->num_of_cmd - 1)
				node->is_error = 1;
		}
		else
			init_path_env_utils(node, path, i);
		i++;
	}
	node->path_env[i] = 0;
}
