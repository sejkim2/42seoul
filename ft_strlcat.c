/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:57:47 by sejkim2           #+#    #+#             */
/*   Updated: 2023/03/21 18:51:22 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//널 문자를 고려한 길이가 인자로 사용되는 strcat류 함수
//dstsize가 dest_size + src_size + 1 일 경우 정상적으로 cat 수행 가능
//반환값은 src의 길이 + min(dst의 길이, 인자로 들어온 dstsize)이며
//src의 길이 + dst의 길이가 반환되었을 경우 올바르게 저장된 경우
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	j = 0;
	while (dst[i])
		i++;
	while (i + 1 < dstsize && src[j])
		dst[i++] = src[j++];
	dst[i] = '\0';
	if (dest_len > dstsize)		//dest_len이 dstsize보다 크면 dst가 오염되지 않음 (변화가 없음)
		return (src_len + dstsize);
	else
		return (src_len + dest_len);	//dst가 dstsize-src_len만큼 오염됨
	//return 값이 복잡하지만 길이끼리 비교할 수 있게 되어서 오염 판단을 하기 
}
