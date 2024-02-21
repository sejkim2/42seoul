/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 09:06:11 by jho               #+#    #+#             */
/*   Updated: 2024/01/30 16:00:27 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/get_next_line.h"

void	gnl_remove_node(t_fd_node **head, int fd)
{
	t_fd_node	*temp;

	if ((*head)->fd == fd)
	{
		temp = *head;
		*head = (*head)->next;
		if (temp->rest != 0)
			free(temp->rest);
		free(temp);
		if (*head != 0)
			(*head)->prev = 0;
	}
	else
	{
		temp = *head;
		while (temp->fd != fd)
			temp = temp->next;
		if (temp->prev != 0)
			temp->prev->next = temp->next;
		if (temp->next != 0)
			temp->next->prev = temp->prev;
		if (temp->rest != 0)
			free(temp->rest);
		free(temp);
	}
}

size_t	gnl_strlen(const char *str)
{
	size_t	len;

	if (str == 0)
		return (0);
	len = 0;
	while (*(str + len) != '\0')
		++len;
	return (len);
}

void	gnl_strcpy(char *dest, char *src, size_t len)
{
	size_t	idx;

	if (src == 0)
		return ;
	idx = 0;
	while (idx < len)
	{
		*(dest + idx) = *(src + idx);
		++idx;
	}
}

char	*gnl_strjoin(char *pre, char *pst)
{
	char	*join;
	size_t	prelen;
	size_t	pstlen;

	prelen = gnl_strlen(pre);
	pstlen = gnl_strlen(pst);
	join = (char *)malloc(prelen + pstlen + 1);
	if (join == 0)
		return (0);
	gnl_strcpy(join, pre, prelen);
	gnl_strcpy(join + prelen, pst, pstlen);
	*(join + prelen + pstlen) = '\0';
	if (pre != 0)
		free(pre);
	return (join);
}

char	*gnl_strchr(const char *s, int c)
{
	size_t	idx;
	size_t	len;

	if (s == 0)
		return (0);
	idx = 0;
	len = gnl_strlen(s);
	while (idx <= len)
	{
		if (*(s + idx) == (char)c)
			return ((char *)(s + idx));
		++idx;
	}
	return (0);
}
