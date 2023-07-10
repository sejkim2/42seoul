/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:26:30 by sejkim2           #+#    #+#             */
/*   Updated: 2023/07/07 12:53:51 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*free_memory(t_game_info *game)
{
	int	i;

	i = 0;
	free(game->map.buf);
	while (i < game->map.height)
	{
		free(game->map.map_table[i]);
		i++;
	}
	if (i > 0)
		free(game->map.map_table);
	return (0);
}

char	*free_visited(t_game_info *game)
{
	int	i;

	i = 0;
	while (i < game->map.height)
	{
		free(game->map.visited[i]);
		i++;
	}
	if (i > 0)
		free(game->map.visited);
	return (0);
}
