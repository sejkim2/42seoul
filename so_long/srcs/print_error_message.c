/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_message.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:26:46 by sejkim2           #+#    #+#             */
/*   Updated: 2023/06/09 15:59:10 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_filename_error_message(int error_num)
{
	if (error_num == 0)
		ft_printf("Error\n->filename has to only one\n");
	else if (error_num == 1)
		ft_printf("Error\n->filename is not exist\n");
	else if (error_num == 2)
		ft_printf("Error\n->map file ending with the .ber extension\n");
	exit(1);
}

void	print_map_error_message(int error_num, t_game_info *game)
{
	if (error_num == 0)
		ft_printf("Error\n->Valid object : 0, 1, P, E, C ONLY\n");
	else if (error_num == 1)
		ft_printf("Error\n->It has to sorround by wall\n");
	else if (error_num == 2)
		ft_printf("Error\n->player has to only one\n");
	else if (error_num == 3)
		ft_printf("Error\n->exit has to only one\n");
	else if (error_num == 4)
		ft_printf("Erorr\n->not valid path\n");
	else if (error_num == 5)
		ft_printf("Error\n->It has to rectangular\n");
	else if (error_num == 6)
		ft_printf("Error\n->map is empty\n");
	free_memory(game);
	exit(1);
}
