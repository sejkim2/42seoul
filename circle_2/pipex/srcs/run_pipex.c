/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pipex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:37:15 by sejkim2           #+#    #+#             */
/*   Updated: 2023/08/18 10:40:14 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void make_process(int index, t_node *node, char **envp)
{
    pid_t pid;

    pid = fork();
    if (pid == 0)
    {
        child_process(index, node);
        if (execve(node->path_env[index], node->cmd[index], envp) == -1)
        {
            // perror("hddfasdadfadfi");
            exit(0);
        }
    }
    else
        parent_process(index, node);
}

void run_pipex(t_node *node, char **envp)
{
    int index;
    int i;

    index = 0;
    i = 0;
    while (index < node->num_of_cmd)
    {
        if (index % 2 == 0)
            pipe(node->pipe_A);
        else
            pipe(node->pipe_B);
        make_process(index, node, envp);
        index++;
    }
    close(node->pipe_A[0]);
    close(node->pipe_A[1]);
    close(node->pipe_B[0]);
    close(node->pipe_B[1]);
    while (i < node->num_of_cmd)
    {
        wait(0);
        i++;
    }
    if (node->is_heredoc == 1)
        unlink("here_doc");
}