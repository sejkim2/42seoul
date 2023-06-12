/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:52:32 by sejkim2           #+#    #+#             */
/*   Updated: 2023/06/12 14:53:24 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_argument_error(int argc, char *filename)
{
	if (argc != 2)
		print_filename_error_message(0);
	if (ft_strnstr(filename, ".ber", ft_strlen(filename)) == 0)
		print_filename_error_message(2);
}

void	init_game(t_game_info **game, char *filename)
{
	*game = make_map(filename);
	check_map_error(*game);
	init_mlx_controller(*game);
}

void	run_game(t_game_info **game)
{
	run_window(*game);
	move_map(*game);
	mlx_loop((*game)->mlx_controller.mlx);
}
