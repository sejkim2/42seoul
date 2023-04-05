/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:09:21 by sejkim2           #+#    #+#             */
/*   Updated: 2023/04/03 14:39:30 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_x(int num, char base)
{
	if (base == 'x')
		return (ft_putnbr_base((unsigned int)num, "0123456789abcdef"));
	else
		return (ft_putnbr_base((unsigned int)num, "0123456789ABCDEF"));
}
