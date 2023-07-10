/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:26:40 by sejkim2           #+#    #+#             */
/*   Updated: 2023/06/27 15:22:23 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	move_if_ground(t_game_info *game, int x_dir, int y_dir)
{
	mlx_put_image_to_window(game->mlx_controller.mlx, game->mlx_controller.win, \
	game->img.ground, game->player.x * SCALE, game->player.y * SCALE);
	game->player.x += x_dir;
	game->player.y += y_dir;
	mlx_put_image_to_window(game->mlx_controller.mlx, game->mlx_controller.win, \
	game->img.character_front, game->player.x * SCALE, game->player.y * SCALE);
}

static void	move_if_chest(t_game_info *game, int x_dir, int y_dir)
{
	mlx_put_image_to_window(game->mlx_controller.mlx, game->mlx_controller.win, \
	game->img.ground, game->player.x * SCALE, game->player.y * SCALE);
	game->player.x += x_dir;
	game->player.y += y_dir;
	mlx_put_image_to_window(game->mlx_controller.mlx, game->mlx_controller.win, \
	game->img.ground, game->player.x * SCALE, game->player.y * SCALE);
	mlx_put_image_to_window(game->mlx_controller.mlx, game->mlx_controller.win, \
	game->img.character_front, game->player.x * SCALE, game->player.y * SCALE);
	game->player.current_getting_chest++;
}

static void	move_if_exit_door(t_game_info *game, int x_dir, int y_dir)
{
	if (game->player.current_getting_chest == game->map.num_of_chest)
	{
		ft_printf("you win!\n");
		close_win(game);
	}
	else
	{
		mlx_put_image_to_window(game->mlx_controller.mlx, \
		game->mlx_controller.win, game->img.ground, \
		game->player.x * SCALE, game->player.y * SCALE);
		game->player.x += x_dir;
		game->player.y += y_dir;
		mlx_put_image_to_window(game->mlx_controller.mlx, \
		game->mlx_controller.win, game->img.character_front, \
		game->player.x * SCALE, game->player.y * SCALE);
	}
}

int	close_win(t_game_info *game)
{
	mlx_destroy_window(game->mlx_controller.mlx, game->mlx_controller.win);
	free_memory(game);
	exit(0);
}

void	move_cordi(t_game_info *game, int next_step, int x_dir, int y_dir)
{
	int	cur_offset;

	cur_offset = (game->map.width + 1) * game->player.y \
	+ game->player.x;
	if (game->map.buf[cur_offset + next_step] == '0')
		move_if_ground(game, x_dir, y_dir);
	else if (game->map.buf[cur_offset + next_step] == 'C')
	{
		move_if_chest(game, x_dir, y_dir);
		game->map.buf[cur_offset + next_step] = '0';
	}
	else if (game->map.buf[cur_offset + next_step] == 'E')
		move_if_exit_door(game, x_dir, y_dir);
	if (game->map.buf[cur_offset] == 'E' && \
	game->map.buf[cur_offset + next_step] == '0')
		mlx_put_image_to_window(game->mlx_controller.mlx, \
	game->mlx_controller.win, game->img.exit_door, \
	(game->player.x - x_dir) * SCALE, (game->player.y - y_dir) * SCALE);
}
