/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 00:01:59 by jho               #+#    #+#             */
/*   Updated: 2024/02/01 14:21:37 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt_parser.h"

t_vec	mrt_color(int r, int g, int b)
{
	return (vec((double)r / 255, (double)g / 255, (double)b / 255));
}
