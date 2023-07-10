/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:26:22 by sejkim2           #+#    #+#             */
/*   Updated: 2023/06/20 18:32:31 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_is_valid_object_and_surrounded_by_walls(t_game_info *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (ft_strchr("01PEC", game->map.map_table[i][j]) == 0)
				print_map_error_message(0, game);
			if ((i == 0) || (i == game->map.height - 1)
				|| (j == 0) || (j == game->map.width - 1))
			{
				if (game->map.map_table[i][j] != '1')
					print_map_error_message(1, game);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static void	set_player_position_and_num_of_object(t_game_info *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map_table[i][j] == 'P')
			{
				game->map.num_of_players++;
				game->player.x = i;
				game->player.y = j;
			}
			else if (game->map.map_table[i][j] == 'E')
				game->map.num_of_exit++;
			else if (game->map.map_table[i][j] == 'C')
				game->map.num_of_chest++;
			j++;
		}
		i++;
	}
}

static void	check_num_of_object(t_game_info *game)
{
	if (game->map.num_of_players != 1)
		print_map_error_message(2, game);
	if (game->map.num_of_exit != 1)
		print_map_error_message(3, game);
	if (game->map.num_of_chest < 1)
		print_map_error_message(7, game);
}

static int	check_visited(t_game_info *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.visited[i][j] == 0
				&& (game->map.map_table[i][j] == 'C'
				|| game->map.map_table[i][j] == 'E'))
				print_map_error_message(4, game);
			j++;
		}
		i++;
	}
	return (1);
}

void	check_map_error(t_game_info *game)
{
	check_is_valid_object_and_surrounded_by_walls(game);
	set_player_position_and_num_of_object(game);
	check_num_of_object(game);
	init_visited(game);
	game->map.visited[game->player.x][game->player.y] = 1;
	dfs(game, game->player.x, game->player.y);
	check_visited(game);
	free_visited(game);
}
