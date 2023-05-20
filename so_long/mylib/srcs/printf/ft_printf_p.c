/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:09:13 by sejkim2           #+#    #+#             */
/*   Updated: 2023/05/20 20:39:56 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_printf.h"

int	ft_printf_p(void *addr)
{
	int	len;

	if (write(1, "0x", 2) == -1)
		return (-1);
	len = ft_putnbr_base((size_t)addr, "0123456789abcdef");
	if (len == -1)
		return (-1);
	else
		return (len + 2);
}

