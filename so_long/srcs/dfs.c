/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:26:27 by sejkim2           #+#    #+#             */
/*   Updated: 2023/06/05 16:35:10 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	return_move_row_size(int i)
{
	int	move_row[4];

	move_row[0] = 0;
	move_row[1] = 0;
	move_row[2] = 1;
	move_row[3] = -1;
	return (move_row[i]);
}

static int	return_move_col_size(int i)
{
	int	move_col[4];

	move_col[0] = 1;
	move_col[1] = -1;
	move_col[2] = 0;
	move_col[3] = 0;
	return (move_col[i]);
}

void	dfs(t_game_info *game, int row, int col)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (i < 4)
	{
		x = return_move_row_size(i) + row;
		y = return_move_col_size(i) + col;
		i++;
		if (x < 0 || y < 0 || x >= game->map.height
			|| y >= game->map.width || game->map.visited[x][y] == 1)
			continue ;
		if (game->map.visited[x][y] == 0)
		{
			if (game->map.map_table[x][y] != '1')
			{
				game->map.visited[x][y] = 1;
				dfs(game, x, y);
			}
		}
	}
}
