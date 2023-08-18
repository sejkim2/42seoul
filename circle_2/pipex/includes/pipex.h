/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:26:11 by sejkim2           #+#    #+#             */
/*   Updated: 2023/08/18 10:40:29 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../mylib/includes/ft_printf.h"
# include "../mylib/includes/get_next_line.h"
# include "../mylib/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>

# define MAX_IND 100000

typedef struct s_node
{
    int num_of_cmd;
    int infile_fd;
    int outfile_fd;
    char ***cmd;
    char **path_env;
    int is_heredoc;
    int pipe_A[2];
    int pipe_B[2];
}	t_node;

int main(int argc, char **argv, char **envp);
void parsing_cmd_and_filename(int argc, char **argv, t_node *node);
void init_path_env(t_node *node, char **path);
void run_pipex(t_node *node, char **envp);
void make_process(int index, t_node *node, char **envp);
void parent_process(int index, t_node *node);
void child_process(int index, t_node *node);
void free_all_data(t_node *node);
void free_path(char **path);

#endif