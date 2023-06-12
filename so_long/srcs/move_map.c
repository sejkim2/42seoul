/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:26:44 by sejkim2           #+#    #+#             */
/*   Updated: 2023/06/09 14:08:09 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	key_hook(int keycode, t_game_info *game)
{
	int	x;
	int	y;

	x = game->player.x;
	y = game->player.y;
	if (keycode == KEY_ESC)
		close_win(game);
	else if (keycode == KEY_A)
		move_cordi(game, -1, -1, 0);
	else if (keycode == KEY_S)
		move_cordi(game, game->map.width + 1, 0, 1);
	else if (keycode == KEY_D)
		move_cordi(game, 1, 1, 0);
	else if (keycode == KEY_W)
		move_cordi(game, (game->map.width + 1) * -1, 0, -1);
	if (x != game->player.x || y != game->player.y)
		ft_printf("walk : %d\n", ++(game->player.walk));
	return (0);
}

void	move_map(t_game_info *game)
{
	game->map.buf[(game->map.width + 1) \
	* game->player.y + game->player.x] = '0';
	mlx_hook(game->mlx_controller.win, KEY_PRESS_EVENT, 0, &key_hook, game);
	mlx_hook(game->mlx_controller.win, KEY_CLICK_EXIT, 0, &close_win, game);
}
