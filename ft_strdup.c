/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:57:41 by sejkim2           #+#    #+#             */
/*   Updated: 2023/03/22 12:30:33 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//문자열을 그대로 복사하여 생성된 새 문자열 반환
char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		i;

	dest = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));	//널을 고려하여 +1
	if (dest == 0)
		return (0);
	i = 0;
	//strlcpy(dest, s1, ft_strlen(s1) + 1))과 
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
