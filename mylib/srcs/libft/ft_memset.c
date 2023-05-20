/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:57:23 by sejkim2           #+#    #+#             */
/*   Updated: 2023/05/20 20:44:47 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

//특정 문자로 메모리 공간을 초기화
void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	void	*p;

	i = 0;
	p = b;
	while (i < len)
	{
		*((unsigned char *)p + i) = (unsigned char)c;
		i++;
	}
	return (b);
}
