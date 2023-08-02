#include "../includes/pipex.h"

// static void child_process(t_node *node, int pipe_fd[2], char **envp)
// {
//     close(pipe_fd[0]);
//     dup2(pipe_fd[1], STDOUT_FILENO);
//     dup2(node->infile_fd, STDIN_FILENO);
//     close(pipe_fd[1]);
//     close(node->infile_fd);
//     execve(node->path_env1, node->cmd1, envp);
// }

// static void parent_process(pid_t pid, t_node *node, int pipe_fd[2], char **envp)
// {
//     close(pipe_fd[1]);
//     dup2(pipe_fd[0], STDIN_FILENO);
//     dup2(node->outfile_fd, STDOUT_FILENO);
//     close(pipe_fd[0]);
//     close(node->outfile_fd);
//     waitpid(pid, 0, 0);
//     execve(node->path_env2, node->cmd2, envp);
// }

void run_pipex(t_node *node, char **envp)
{
    // pid_t pid;
    // int pipe_fd[2];
    
    if (pipe(node->pipe_fd) < 0)
    {
        ft_printf("pipe error\n");
        exit(1);
    }
    node->pid = fork();
    if (node->pid == -1)
    {
        ft_printf("fork error\n");
        exit(1);
    }
    else if (node->pid == 0)
    {
        
        close(node->pipe_fd[0]);
        dup2(node->pipe_fd[1], STDOUT_FILENO);
        dup2(node->infile_fd, STDIN_FILENO);
        close(node->pipe_fd[1]);
        close(node->infile_fd);
        execve(node->path_env1, node->cmd1, envp);
    }
    // child_process(node, pipe_fd, envp);
    else
    {
        
        close(node->pipe_fd[1]);
        dup2(node->pipe_fd[0], STDIN_FILENO);
        dup2(node->outfile_fd, STDOUT_FILENO);
        close(node->pipe_fd[0]);
        close(node->outfile_fd);
        waitpid(node->pid, 0, 0);
        execve(node->path_env2, node->cmd2, envp);
    }
        // parent_process(pid, node, pipe_fd, envp);
}