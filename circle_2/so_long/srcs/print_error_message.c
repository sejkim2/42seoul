/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_message.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:26:46 by sejkim2           #+#    #+#             */
/*   Updated: 2023/06/27 15:20:53 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_filename_error_message(int error_num)
{
	if (error_num == 0)
		ft_printf("Error\n->Filename has to only one\n");
	else if (error_num == 1)
		ft_printf("Error\n->Filename is not exist\n");
	else if (error_num == 2)
		ft_printf("Error\n->Filename ending with the .ber extension\n");
	else if (error_num == 3)
		ft_printf("Error\n->Filename has to be longer than 4 characters\n");
	exit(1);
}

void	print_map_error_message(int error_num, t_game_info *game)
{
	if (error_num == 0)
		ft_printf("Error\n->Valid object : 0, 1, P, E, C ONLY\n");
	else if (error_num == 1)
		ft_printf("Error\n->It has to be surrounded by wall\n");
	else if (error_num == 2)
		ft_printf("Error\n->Player has to only one\n");
	else if (error_num == 3)
		ft_printf("Error\n->Exit has to only one\n");
	else if (error_num == 4)
		ft_printf("Erorr\n->Not valid path\n");
	else if (error_num == 5)
		ft_printf("Error\n->It has to be rectangular\n");
	else if (error_num == 6)
		ft_printf("Error\n->Map is empty\n");
	else if (error_num == 7)
		ft_printf("Error\n->Map must contain at least 1 collectible.\n");
	else if (error_num == 8)
		ft_printf("Error\n->Close error\n");
	else if (error_num == 9)
		ft_printf("Erro\n->Memory has not enough\n");
	else if (error_num == 10)
		ft_printf("Error\n->Map size is too big\n");
	free_memory(game);
	exit(1);
}
