/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:57:21 by sejkim2           #+#    #+#             */
/*   Updated: 2023/03/21 18:42:02 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//memcpy 함수에서 overlap 문제를 해결하기 위해 보완된 함수

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst == src)
		return (dst);
	if (dst < src)
		dst = ft_memcpy(dst, src, len);
	else
	{
		i = len;
		while (i-- > 0)
			*((unsigned char *)dst + i) = *((unsigned char *)src + i);
	}
	return (dst);
}
