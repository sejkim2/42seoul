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

typedef struct s_node
{
    pid_t pid;
    int pipe_fd[2];
    
    int infile_fd;
    int outfile_fd;
    char **cmd1;
    char **cmd2;
    char *infile_name;
    char *outfile_name;
    char *path_env1;
    char *path_env2;
}	t_node;

int main(int argc, char **argv, char **envp);
void run_pipex(t_node *node, char **envp);

#endif