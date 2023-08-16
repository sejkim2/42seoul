/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:26:11 by sejkim2           #+#    #+#             */
/*   Updated: 2023/08/16 13:21:22 by sejkim2          ###   ########.fr       */
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
}	t_node;

int main(int argc, char **argv, char **envp);
void parsing_cmd_and_filename(int argc, char **argv, t_node *node);
void run_pipex(t_node *node, char **envp);
void free_all_data(char **path, t_node *node);

#endif