/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:57:21 by sejkim2           #+#    #+#             */
/*   Updated: 2023/05/20 20:44:44 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

//memcpy 함수에서 overlap 문제를 해결하기 위해 보완된 함수
//		[dst][][][][]
//	[src][][][][]
//위의 경우 (dst > src) 주소가 겹치므로 마지막 주소부터 감소하며 값을 넣게 되면 원래 src의 값들이 dst에 변경되지 않고 잘 저장된다. (원본 src는 변경됨)
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst == src)
		return (dst);
	if (dst < src)
		dst = ft_memcpy(dst, src, len);		//겹치지 않을 경우 memcpy 호출하여 복사
	else
	{
		i = len;
		while (i-- > 0)
			*((unsigned char *)dst + i) = *((unsigned char *)src + i);	//겹칠 경우 끝 주소부터 감소하며 
	}
	return (dst);
}
