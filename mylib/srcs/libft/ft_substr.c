/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:58:06 by sejkim2           #+#    #+#             */
/*   Updated: 2023/05/20 20:45:37 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

//부분 문자열의 최대 크기는 len이며 할당 시 최적화 된 크기만큼만 할당
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	s_len;
	size_t	i;
	size_t	size;

	s_len = ft_strlen(s);
	i = 0;
	if (start >= s_len)	//시작 위치가 문자열 길이를 넘어갈 경우 빈 문자열 반환
	{
		dest = (char *)malloc(sizeof(char) * 1);
		if (dest == 0)
			return (0);
		*dest = 0;
		return (dest);
	}
	//할당할 크기 최적화 min(문자열 길이 - 시작 위치, 인자로 받은 길이)
	if (s_len - start < len)
		size = s_len - start;
	else
		size = len;
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (dest == 0)
		return (0);
	ft_strlcpy(dest, s + start, size + 1);
	return (dest);
}
