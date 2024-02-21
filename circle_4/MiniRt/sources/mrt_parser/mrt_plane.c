/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:02:44 by jho               #+#    #+#             */
/*   Updated: 2024/02/01 17:11:36 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mrt_parser.h"

t_obj	*mrt_plane(t_vec center, t_vec normal)
{
	t_obj	*plane;

	plane = malloc(sizeof(t_obj));
	if (plane == NULL)
		ft_except("Malloc failed.", errno);
	plane->type = PL;
	plane->origin = center;
	plane->axis = normal;
	plane->albedo = mrt_color(255, 0, 0);
	plane->next = NULL;
	return (plane);
}
