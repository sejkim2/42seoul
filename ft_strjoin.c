/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:57:45 by sejkim2           #+#    #+#             */
/*   Updated: 2023/03/21 18:49:44 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//s1 + s2 인 새 문자열을 생성하여 반환
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*dest;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (dest == 0)
		return (0);
	ft_strlcpy(dest, s1, s1_len + 1);	//빈 공간 dest에 s1을 복사
	ft_strlcat(dest, s2, s1_len + s2_len + 1);	//dest에 s2를 붙이기
	return (dest);
}
