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

# define MAX_IND 100000

int main(int argc, char **argv, char **envp);

typedef struct s_node
{
    int fd[2];
    char *cmd1;
    char *cmd2;
    char *infile_name;
    char *outfile_name;
    char **path_env;
}	t_node;

#endif