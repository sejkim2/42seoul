/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:26:38 by sejkim2           #+#    #+#             */
/*   Updated: 2023/07/07 13:00:24 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	run_gnl(t_game_info *game)
{
	char	*tmp;
	char	*free_buf;

	while (1)
	{
		tmp = get_next_line(game->map.fd);
		if (tmp == 0)
			break ;
		free_buf = game->map.buf;
		game->map.buf = ft_strjoin(game->map.buf, tmp);
		free(free_buf);
		free(tmp);
		game->map.height++;
	}
}

static	int	check_map_height(t_game_info *game)
{
	char	**p;
	int		i;

	p = game->map.map_table;
	i = 0;
	while (p[i])
		i++;
	if (game->map.height != i)
	{
		game->map.height = i;
		return (0);
	}
	else
		return (1);
}

static int	init_map_width(t_game_info	*game)
{
	char	**p;
	size_t	len_width;
	int		i;

	p = game->map.map_table;
	len_width = ft_strlen(p[0]);
	i = 1;
	while (p[i] != 0)
	{
		if (ft_strlen(p[i]) != len_width)
			return (0);
		else
			i++;
	}
	return ((int)len_width);
}

void	make_map(t_game_info *game, char	*filename)
{
	init_game_object(game, filename);
	run_gnl(game);
	if (game->map.buf[0] == '\0')
		print_map_error_message(6, game);
	game->map.map_table = ft_split(game->map.buf, '\n');
	if (!check_map_height(game))
		print_map_error_message(5, game);
	if (game->map.buf[ft_strlen(game->map.buf) - 1] == '\n')
		print_map_error_message(5, game);
	game->map.width = init_map_width(game);
	if (game->map.height < 3 || game->map.width == 0)
		print_map_error_message(5, game);
	if (game->map.height > MAX_HEIGHT_SIZE || game->map.width > MAX_WIDTH_SIZE)
		print_map_error_message(10, game);
	if (close(game->map.fd) < 0)
		print_map_error_message(8, game);
}
