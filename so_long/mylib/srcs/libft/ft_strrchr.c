/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:57:59 by sejkim2           #+#    #+#             */
/*   Updated: 2023/05/20 20:45:31 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

//strchr과 비슷하지만 이 함수는 마지막으로 일치하는 문자의 위치를 반환
char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	len;
	char	*p;
	char	*result;	//일치하는 문자의 위치 기록

	p = (char *)s;
	result = 0;
	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (*(p + i) == (char)c)
			result = p + i;	//일치 문자 위치 
		i++;
	}
	return (result);
}
