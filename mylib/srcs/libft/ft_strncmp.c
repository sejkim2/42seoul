/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:57:55 by sejkim2           #+#    #+#             */
/*   Updated: 2023/05/20 20:45:26 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

//n 바이트만큼 두 문자열을 비교
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{	
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	i = 0;
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	if (p1 == p2)		//두 문자열이 같다면 (널포인터 포함) 비교할 필요 없음
		return (0);
	while (i < n && (p1[i] || p2[i]))	//크기 내에서 두 문자열 중 하나라도 널이 아니면 비교
	{
		if (p1[i] == p2[i])
			i++;
		else
			return (p1[i] - p2[i]);
	}
	return (0);
}
