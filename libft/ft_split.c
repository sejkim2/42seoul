/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:57:36 by sejkim2           #+#    #+#             */
/*   Updated: 2023/03/23 15:27:19 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//끊어지는 문자열의 개수
size_t	row_size(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		// 1. 구분자를 먼저 민다 : 개수에 영향을 주지 않음
		while (s[i] == c)
			i++;
		//문자열 범위 내에서 구분자가 아닌 정상 문자를 전부 밀고 다 밀면 저장할 부분 문자열의 개수를 하나 더 올림 : 구분자 다음 나오는 정상 문자는 개수에 영향을 준다
		if (s[i])
		{
			while (s[i] != c && s[i])	//구분자 - 정상 문자 - 구분자 혹은 널문자(문자열의 끝)
				i++;
			count++;
		}
	}
	return (count);
}

//구분자로 나누어 진 문자열 동적 할당 (크기는 tail - head)
int	make_split_string(char **table, const char *s, size_t head, size_t tail)
{
	size_t	i;

	i = 0;
	*table = (char *)malloc(sizeof(char) * (tail - head + 1));	//마지막 널 문자를 고려해서 +1
	if (*table == 0)
		return (0);
	while (i < tail - head)
	{
		(*table)[i] = s[i + head];
		i++;
	}
	(*table)[i] = '\0';
	return (1);
}

//동적 할당 도중 실패하면 그 전에 할당한 모든 공간을 해제하고 널포인터 반환
char	**free_split(char **table, int row)
{
	int	i;

	i = 0;
	while (i < row)
		free(table[i++]);	//할당한 일차원 배열 해체
	free(table);	//할당한 이차원 배열 해제
	return (0);
}

// 입력받은 문자열을 특정 문자를 기준으로 나누기
char	**ft_split(char const *s, char c)
{
	char	**table;
	size_t	row;
	size_t	i;
	size_t	head;

	i = 0;
	row = 0;
	table = (char **)malloc(sizeof(char *) * (row_size(s, c) + 1));		//나누는 문자열의 개수 + 1 (이차원 문자열 배열 역시 마지막을 널로 구분)
	if (table == 0)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			head = i;	//할당할 크기의 문자열의 첫번째 인덱스
			while (s[i] != c && s[i])
				i++;
			if (!make_split_string(&(table[row++]), s, head, i))	//할당에 실패하면 모든 메모리 해제
				return (free_split(table, row - 1));
		}
	}
	table[row] = 0;	//이차원 배열의 마지막에 
	return (table);
}
