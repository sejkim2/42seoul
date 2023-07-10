/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:57:18 by sejkim2           #+#    #+#             */
/*   Updated: 2023/03/21 18:40:53 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//dest에 src를 n바이트만큼 복사
//메모리가 겹치는 상황을 고려하지 않음 (overlap x)
//		[dst][][][][]
//	[src][][][][]
//위의 경우 src의 마지막이 dst의 첫번째와 겹치기 때문에 주소 이동을 증가시킬 경우 src의 값이 변경될 수 있다.
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == src)	//두 문자열이 널포인터 (초기 주소, 아무것도 안들어있음) 이거나 같으면 복사할 필요가 없음
		return (dest);
	while (i < n)
	{
		*((unsigned char *)dest + i) = *((unsigned char *)src + i);
		i++;
	}
	return (dest);
}
