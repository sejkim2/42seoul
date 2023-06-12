/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:26:55 by sejkim2           #+#    #+#             */
/*   Updated: 2023/06/12 14:23:38 by sejkim2          ###   ########.fr       */
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

# include "../mylib/includes/libft.h"
# include "../mylib/includes/ft_printf.h"
# include "../mylib/includes/get_next_line.h"
# include "../mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_map_info
{
	int		height;
	int		width;
	int		fd;
	char	*buf;
	char	**map_table;
	int		**visited;
	char	*filename;
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
void		check_argument_error(int argc, char *filename);
void		init_game(t_game_info **game, char *filename);
void		run_game(t_game_info **game);
t_game_info	*make_map(char	*filename);
void		run_window(t_game_info *game);
void		move_map(t_game_info *game);
int			check_map_error(t_game_info *game);
void		print_filename_error_message(int error_num);
void		print_map_error_message(int error_num, t_game_info *game);
char		*free_memory(t_game_info *game);
t_game_info	*init_game_object(char *filename);
void		dfs(t_game_info *game, int row, int col);
void		move_cordi(t_game_info *game, int next_step, int x_dir, int y_dir);
int			close_win(t_game_info *game);
void		init_mlx_controller(t_game_info *game);

#endif
