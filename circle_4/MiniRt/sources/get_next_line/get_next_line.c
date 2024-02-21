/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 09:05:39 by jho               #+#    #+#             */
/*   Updated: 2024/01/30 16:00:34 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/get_next_line.h"

char	*gnl_mfree(char **p1, char *p2, t_fd_node **head, int fd)
{
	if (p1 != 0 && *p1 != 0)
	{
		free(*p1);
		*p1 = 0;
	}
	if (head != 0 && *head != 0)
		gnl_remove_node(head, fd);
	return (p2);
}

int	read_next_chunk(int fd, char **rest)
{
	char	*buffer;
	int		size;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == 0)
		return (0);
	while (gnl_strchr(*rest, '\n') == 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1 || (*rest == 0 && size == 0))
			return ((int)gnl_mfree(&buffer, 0, 0, 0));
		if (size == 0)
			break ;
		*(buffer + size) = '\0';
		*rest = gnl_strjoin(*rest, buffer);
		if (*rest == 0)
			return ((int)gnl_mfree(&buffer, 0, 0, 0));
	}
	gnl_mfree(&buffer, 0, 0, 0);
	return (1);
}

char	*get_next_rest(t_fd_node **head, t_fd_node *node)
{
	size_t	len;
	char	*buffer;
	char	*next_line;

	len = 0;
	while (*(node->rest + len) != '\n' && *(node->rest + len) != '\0')
		++len;
	if (*(node->rest + len) == '\n')
		++len;
	next_line = (char *)malloc(sizeof(char) * (len + 1));
	if (next_line == 0)
		return (gnl_mfree(0, 0, head, node->fd));
	gnl_strcpy(next_line, node->rest, len);
	*(next_line + len) = '\0';
	if (*(node->rest + len) == '\0')
		return (gnl_mfree(0, next_line, head, node->fd));
	buffer = (char *)malloc((gnl_strlen(node->rest + len) + 1));
	if (buffer == 0)
		return (gnl_mfree(0, next_line, head, node->fd));
	gnl_strcpy(buffer, (node->rest) + len, gnl_strlen(node->rest + len));
	*(buffer + gnl_strlen(node->rest + len)) = '\0';
	gnl_mfree(&(node->rest), 0, 0, 0);
	node->rest = buffer;
	return (next_line);
}

t_fd_node	*addfirst(t_fd_node **head, int fd)
{
	t_fd_node	*node;

	node = (t_fd_node *)malloc(sizeof(t_fd_node));
	if (node == 0)
		return (0);
	node->fd = fd;
	node->rest = 0;
	node->prev = 0;
	if (*head != 0)
	{
		node->next = *head;
		(*head)->prev = node;
	}
	else
		node->next = 0;
	*head = node;
	return (node);
}

char	*get_next_line(int fd)
{
	static t_fd_node	*head;
	t_fd_node			*node;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	if (head == 0)
		node = addfirst(&head, fd);
	else
	{
		node = head;
		while (node != 0 && node->fd != fd)
			node = node->next;
		if (node == 0)
			node = addfirst(&head, fd);
	}
	if (node == 0)
		return (0);
	if (read_next_chunk(fd, &(node->rest)) == 0)
		return (gnl_mfree(0, 0, &head, node->fd));
	return (get_next_rest(&head, node));
}
