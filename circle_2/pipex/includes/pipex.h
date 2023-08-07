/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:26:11 by sejkim2           #+#    #+#             */
/*   Updated: 2023/08/07 18:02:51 by sejkim2          ###   ########.fr       */
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
    // char **cmd1;
    // char **cmd2;
    char *infile_name;
    char *outfile_name;
    char **path_env;
    // char *path_env1;
    // char *path_env2;
}	t_node;

int main(int argc, char **argv, char **envp);
void run_pipex(t_node *node, char **envp);

#endif