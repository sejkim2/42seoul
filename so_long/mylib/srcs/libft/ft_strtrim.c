/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:58:03 by sejkim2           #+#    #+#             */
/*   Updated: 2023/05/20 20:45:34 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

//양끝에서 구분자를 제외하고 새 문자열을 생성하여 반환

//해당 문자가 구분자인지 조사
int	is_set(char ch, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (ch == set[i])
			return (i);	//구분자가 맞으면 0 이상의 정수 반환
		else
			i++;
	}
	return (-1);		//없으면 -1 반환
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	head;
	size_t	tail;
	size_t	s1_len;
	char	*dest;

	//s1이 비어있다면 구분자가 없다는 이야기 이므로 그대로 s1을 복사하여 반환
	//set이 비어있다면 구분자가 없다는 이야기 이므로 그대로 s1을 복사하여 반환
	//*s1 == *set 인 경우는 둘 다 0일 때는 문제가 없지만 구분자 집합과 문자열이 일치할 경우 빈 배열이 반환되지 않고 s1이 복사되어서 반환됨
	if (*s1 == 0 || *set == 0)
	{
		dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
		if (dest == 0)
			return (0);
		ft_strlcpy(dest, s1, ft_strlen(s1) + 1);
		return (dest);
	}
	s1_len = ft_strlen(s1);
	head = 0;
	tail = s1_len - 1;
	//문자열의 앞부분에서 구분자를 제거
	while (head < s1_len && is_set(s1[head], set) > -1)
		head++;
	//문자열의 뒷부분에서 구분자를 제거
	while (tail > head && is_set(s1[tail], set) > -1)
		tail--;
	dest = (char *)malloc(sizeof(char) * (tail - head + 2));	//널 문자까지 고려한 크기 
	if (dest == 0)
		return (0);
	ft_strlcpy(dest, s1 + head, tail - head + 2);
	return (dest);
}
