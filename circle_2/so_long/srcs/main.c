/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:26:36 by sejkim2           #+#    #+#             */
/*   Updated: 2023/07/07 13:05:47 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	t_game_info	game;

	if (argc != 2)
		print_filename_error_message(0);
	check_argument_error(ft_strlen(argv[1]), argv[1]);
	init_game(&game, argv[1]);
	run_game(&game);
	return (0);
}
