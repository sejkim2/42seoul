/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_argument.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:59:46 by sejkim2           #+#    #+#             */
/*   Updated: 2023/07/20 18:14:35 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	int	count_word(char *str)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			while (str[i] && str[i] != ' ')
				i++;
			wc++;
		}
		else
			i++;
	}
	if (wc == 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (wc);
}

long long	*parsing_argument(int argc, char **argv, int *word_count)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
			*word_count += count_word(argv[i]);
		else
		{
			if (argv[i][0] == '\0')
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			*word_count += 1;
		}
		i++;
	}
	return (change_string_to_num(*word_count, argc, argv));
}
