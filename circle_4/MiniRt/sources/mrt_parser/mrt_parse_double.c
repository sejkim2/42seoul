/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_parse_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:20:28 by sejkim2           #+#    #+#             */
/*   Updated: 2024/02/03 13:51:26 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt_parser.h"

t_bool	mrt_atod(double *d, char *token, char end)
{
	int		sign;
	double	decimal;

	if (token == NULL || verify_integer_or_decimal(&token, end) == FALSE)
		return (FALSE);
	*d = 0;
	sign = 1;
	if (*token == '-')
	{
		sign = -1;
		++token;
	}
	while (*token >= '0' && *token <= '9')
		*d = (*d * 10) + (*(token++) - '0');
	if (*token == '.')
	{
		decimal = 0.1;
		while (*(++token) >= '0' && *token <= '9')
		{
			*d += (*(token) - '0') * decimal;
			decimal *= 0.1;
		}
	}
	*d *= sign;
	return (*token == end);
}

t_bool	mrt_parse_double(double	*d, char *line, char end, size_t target_index)
{
	char	*token;
	t_bool	b_parse_success;

	token = ft_token(line, target_index);
	if (token == NULL)
		return (FALSE);
	b_parse_success = mrt_atod(d, token, end);
	free(token);
	return (b_parse_success);
}
