/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:57:14 by sejkim2           #+#    #+#             */
/*   Updated: 2023/05/20 20:44:35 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

//n바이트 만큼 조사하면서 찾는 문자가 나오면 해당 주소를 반환
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	ch;
	size_t			i;

	p = (unsigned char *)s;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*(p + i) == ch)
			return (p + i);
		else
			i++;
	}
	return (0);	//문자열을 전부 조사했는데 찾는 문자가 나오지 않으면 널포인터 반환
}
