/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:26:30 by sejkim2           #+#    #+#             */
/*   Updated: 2023/06/09 14:27:55 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*free_memory(t_game_info *game)
{
	int	i;

	i = 0;
	free(game->map.buf);
	free(game->map.filename);
	while (i < game->map.height)
	{
		free(game->map.map_table[i]);
		free(game->map.visited[i]);
		i++;
	}
	free(game->map.map_table);
	free(game->map.visited);
	free(game);
	return (0);
}
