/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:57:36 by sejkim2           #+#    #+#             */
/*   Updated: 2023/03/23 13:57:38 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	row_size(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			while (s[i] != c && s[i])
				i++;
			count++;
		}
	}
	return (count);
}

int	make_split_string(char **table, const char *s, size_t head, size_t tail)
{
	size_t	i;

	i = 0;
	*table = (char *)malloc(sizeof(char) * (tail - head + 1));
	if (*table == 0)
		return (0);
	while (i < tail - head)
	{
		(*table)[i] = s[i + head];
		i++;
	}
	(*table)[i] = '\0';
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**table;
	size_t	row;
	size_t	i;
	size_t	head;
	size_t	j;

	j = 0;
	i = 0;
	row = 0;
	table = (char **)malloc(sizeof(char *) * (row_size(s, c) + 1));
	if (table == 0)
		return (0);
	while (s[i])
    {
        while (s[i] == c)
            i++;
        if (s[i])
        {
            head = i;
            while (s[i] != c && s[i])
                i++;
            if (!make_split_string(&(table[row]), s, head, i))
			{
                while (j < row)
                    free(table[j++]);
                free(table);
                return (0);
            }
            row++;
        }
    }
	table[row] = 0;
	return (table);
}
