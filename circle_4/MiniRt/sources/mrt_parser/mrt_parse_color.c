/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:27:40 by sejkim2           #+#    #+#             */
/*   Updated: 2024/02/03 15:21:07 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt_parser.h"

static	t_bool	atod(double *color, int *index, char *token)
{
	if (!token[*index])
		return (FALSE);
	while (token[*index] >= '0' && token[*index] <= '9')
	{
		*color = (*color * 10) + (token[(*index)++] - '0');
		if (*color < 0 || *color > 255)
			return (FALSE);
	}
	return (TRUE);
}

static	t_bool	mrt_parse_c(t_vec *color, char *token)
{
	int		index;

	index = 0;
	color->x = 0;
	color->y = 0;
	color->z = 0;
	if (atod(&(color->x), &index, token) == FALSE)
		return (FALSE);
	if (token[index++] != ',')
		return (FALSE);
	if (atod(&(color->y), &index, token) == FALSE)
		return (FALSE);
	if (token[index++] != ',')
		return (FALSE);
	if (atod(&(color->z), &index, token) == FALSE)
		return (FALSE);
	if (token[index])
		return (FALSE);
	color->x /= 255;
	color->y /= 255;
	color->z /= 255;
	return (TRUE);
}

t_bool	mrt_parse_color(t_vec *c, char *line, size_t target_index)
{
	char	*token;
	t_bool	b_parse_success;

	token = ft_token(line, target_index);
	if (token == NULL)
		return (FALSE);
	b_parse_success = mrt_parse_c(c, token);
	free(token);
	return (b_parse_success);
}
