/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:26:55 by sejkim2           #+#    #+#             */
/*   Updated: 2023/07/05 12:39:47 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define KEY_PRESS_EVENT	2
# define KEY_CLICK_EXIT		17
# define KEY_ESC			53
# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2

# define SCALE				64
# define MAX_HEIGHT_SIZE	20
# define MAX_WIDTH_SIZE		40

# include "../mylib/includes/libft.h"
# include "../mylib/includes/ft_printf.h"
# include "../mylib/includes/get_next_line.h"
# include "../mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_map_info
{
	int		height;
	int		width;
	int		fd;
	char	*buf;
	char	**map_table;
	int		**visited;
	int		num_of_players;
	int		num_of_exit;
	int		num_of_chest;
}	t_map_info;

typedef struct s_player_info
{
	int		x;
	int		y;
	int		current_getting_chest;
	int		walk;
}	t_player_info;

typedef struct s_mlx_info
{
	void	*mlx;
	void	*win;
}	t_mlx_info;

typedef struct s_image_info
{
	void	*ground;
	void	*tree;
	void	*exit_door;
	void	*chest;
	void	*character_front;
}	t_image_info;

typedef struct s_game_info
{
	t_map_info		map;
	t_player_info	player;
	t_mlx_info		mlx_controller;
	t_image_info	img;
}	t_game_info;

int			main(int argc, char *argv[]);
void		check_argument_error(int filename_len, char *filename);
void		init_game(t_game_info *game, char *filename);
void		run_game(t_game_info *game);
void		make_map(t_game_info *game, char *filename);
void		run_window(t_game_info *game);
void		move_map(t_game_info *game);
void		check_map_error(t_game_info *game);
void		print_filename_error_message(int error_num);
void		print_map_error_message(int error_num, t_game_info *game);
char		*free_memory(t_game_info *game);
char		*free_visited(t_game_info *game);
void		init_game_object(t_game_info *game, char *filename);
void		dfs(t_game_info *game, int row, int col);
void		init_visited(t_game_info *game);
void		move_cordi(t_game_info *game, int next_step, int x_dir, int y_dir);
int			close_win(t_game_info *game);
void		init_mlx_controller(t_game_info *game);

#endif
