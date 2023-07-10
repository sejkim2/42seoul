/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:26:33 by sejkim2           #+#    #+#             */
/*   Updated: 2023/06/20 17:42:16 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	init_map(t_game_info *game, char	*filename)
{
	game->map.height = 0;
	game->map.width = 0;
	game->map.fd = open(filename, O_RDONLY, 0644);
	if (game->map.fd < 0)
		print_filename_error_message(1);
	game->map.buf = ft_strdup("");
	game->map.map_table = 0;
	game->map.visited = 0;
	game->map.num_of_players = 0;
	game->map.num_of_exit = 0;
	game->map.num_of_chest = 0;
}

static void	init_player(t_game_info	*game)
{
	game->player.x = 0;
	game->player.y = 0;
	game->player.current_getting_chest = 0;
	game->player.walk = 0;
}

void	init_mlx_controller(t_game_info *game)
{
	int	img_width;
	int	img_height;

	game->mlx_controller.mlx = mlx_init();
	game->img.ground = mlx_xpm_file_to_image(game->mlx_controller.mlx, \
	"textures/ground.xpm", &img_width, &img_height);
	game->img.tree = mlx_xpm_file_to_image(game->mlx_controller.mlx, \
	"textures/tree.xpm", &img_width, &img_height);
	game->img.exit_door = mlx_xpm_file_to_image(game->mlx_controller.mlx, \
	"textures/exit_door.xpm", &img_width, &img_height);
	game->img.chest = mlx_xpm_file_to_image(game->mlx_controller.mlx, \
	"textures/treasure_box.xpm", &img_width, &img_height);
	game->img.character_front = mlx_xpm_file_to_image(game->mlx_controller.mlx, \
	"textures/character_front.xpm", &img_width, &img_height);
	game->mlx_controller.win = mlx_new_window(game->mlx_controller.mlx, \
	SCALE * game->map.width, SCALE * game->map.height, "so_long");
}

void	init_game_object(t_game_info *game, char *filename)
{
	init_map(game, filename);
	init_player(game);
}
