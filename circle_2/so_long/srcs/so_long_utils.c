/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:52:32 by sejkim2           #+#    #+#             */
/*   Updated: 2023/06/21 14:55:08 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_argument_error(int filename_len, char *filename)
{
	if (filename_len < 5 || filename[filename_len - 5] == '/')
		print_filename_error_message(3);
	if (ft_strnstr(filename + filename_len - 4, \
	".ber", filename_len) == 0)
		print_filename_error_message(2);
}

void	init_game(t_game_info *game, char *filename)
{
	make_map(game, filename);
	check_map_error(game);
	init_mlx_controller(game);
}

void	run_game(t_game_info *game)
{
	run_window(game);
	move_map(game);
	mlx_loop(game->mlx_controller.mlx);
}
