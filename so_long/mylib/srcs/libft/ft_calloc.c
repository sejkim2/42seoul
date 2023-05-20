/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:56:27 by sejkim2           #+#    #+#             */
/*   Updated: 2023/05/20 20:43:28 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

//malloc과 비슷하지만 malloc은 쓰레기 값으로 채워주는 것에 비해
//colloc은 '\0'으로 채워준다.
void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	//void형 포인터의 주소 연산시 1byte씩 접근하기 위해서 char 또는 unsigned char로 형변환하며
	//여기서는 c99에 의거하여 unsigned char로 형변환
	p = (unsigned char *)malloc(count * size);
	if (p == 0)
		return (0);
	while (i < count * size)
		p[i++] = 0;	//주소를 0으로 초기화 (널포인터)가 아니고 메모리 공간을 0으로 초기화 
	return (p);
}
