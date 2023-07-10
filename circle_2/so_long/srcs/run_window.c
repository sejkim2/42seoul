/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:26:48 by sejkim2           #+#    #+#             */
/*   Updated: 2023/06/20 18:03:02 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	put_image(t_game_info *game, char ch, int *row, int *col)
{
	if (ch == '1')
		mlx_put_image_to_window(game->mlx_controller.mlx, \
	game->mlx_controller.win, game->img.tree, (*col) * SCALE, (*row) * SCALE);
	else if (ch == 'C')
	{
		mlx_put_image_to_window(game->mlx_controller.mlx, \
game->mlx_controller.win, game->img.chest, (*col) * SCALE, (*row) * SCALE);
	}
	else if (ch == 'E')
		mlx_put_image_to_window(game->mlx_controller.mlx, \
game->mlx_controller.win, game->img.exit_door, (*col) * SCALE, (*row) * SCALE);
	else if (ch == 'P')
	{
		mlx_put_image_to_window(game->mlx_controller.mlx, \
		game->mlx_controller.win, game->img.character_front, \
		(*col) * SCALE, (*row) * SCALE);
		game->player.x = *col;
		game->player.y = *row;
	}
	else if (ch == '\n')
	{
		*col = -1;
		(*row)++;
	}
}

void	run_window(t_game_info *game)
{
	char	ch;
	int		index;
	int		row;
	int		col;

	index = 0;
	row = 0;
	col = 0;
	while (game->map.buf[index])
	{
		ch = game->map.buf[index++];
		if (ch != '\n')
			mlx_put_image_to_window(game->mlx_controller.mlx, \
		game->mlx_controller.win, game->img.ground, \
		(col) * SCALE, (row) * SCALE);
		put_image(game, ch, &row, &col);
		col++;
	}
}
