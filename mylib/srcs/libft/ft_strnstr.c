/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:57:57 by sejkim2           #+#    #+#             */
/*   Updated: 2023/05/20 20:45:29 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

//길이 내에서 부분 문자열이 있는지 조사하여 있다면 그 주소 반환
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_size;
	char	*str;
	char	*to_find;

	str = (char *)haystack;
	to_find = (char *)needle;
	needle_size = ft_strlen(needle);
	if (*to_find == 0)		//찾고자 하는 문자열이 (널로) 비어있을 때 (널포인터와는 다름)
		return (str);
	i = 0;
	while (str[i] && i < len)
	{
		if (str[i] == to_find[0])	//첫번째 문자가 일치하면 조사할 조건을 만족
		{
			j = 0;	//j = 1이 더 정확
			//길이 내에서 && 찾고자 하는 문자열의 길이 내에서 && 같은지 조사하면서
			while (i + j < len && j < needle_size && str[i + j] == to_find[j])
				j++;
			if (j == needle_size)	//반복문 탈출 이후 크기를 조사해서 그 크기가 찾고자 하는 문자열 크기와 같다면 전부 조사해서 문자가 
				return (str + i);
		}
		i++;
	}
	return (0);
}
