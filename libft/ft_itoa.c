/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:55:24 by sejkim2           #+#    #+#             */
/*   Updated: 2023/03/22 14:24:21 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//할당할 크기를 구하기 위해 정수의 자리수를 계산
int	len_num(const int n)
{
	long long	num;	//오버플로우 방지를 위해 long long으로 선언
	int			is_minus;	//음수라면 '-'까지 고려한 크기를 할당해야 하므로 가변 길이에 대한 변수 선언
	int			len;

	is_minus = 0;
	num = n;
	len = 0;
	if (n <= 0)
	{
		is_minus = 1;
		num = (long long)-1 * (n);
	}
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	return (len + is_minus);	//부호 판별 변수와 정수의 길이를 더한 값을 
}

char	*num_to_string(char *dest, int n, int len)
{
	long long	num;
	int			i;

	i = len;
	dest[i--] = '\0';	//문자열의 마지막에 널 문자 저장
	num = (long long)n;	//정수가 -2147483648일 경우 양수로 변환할 때 오버플로우가 발생하기 때문에 long long으로 형변환
	//long의 경우 운영체제마다 크기가 달라 안전하지 않음
	if (num == 0)
	{
		dest[0] = '0';
		return (dest);
	}
	else if (num < 0)
	{
		dest[0] = '-';		//음수이면 배열 첫번째 값이 '-'
		num = (-1) * num;	//몫 연산을 위해 양수로 바꿔주고 오버플로우 방지를 위해 long long으로 선언
	}
	while (num > 0)
	{
		//배열의 마지막부터 문자(int - '0')를 저장하기 때문에
		//음수이면 '-' 앞에서 멈추고 양수이면 인덱스가 0까지 간다.
		dest[i--] = num % 10 + '0';	//마지막 문자부터 넣어주기 때문에 나머지 연산
		num = num / 10;			//한자리이면 0이 저장되고 다음 반복문에서 탈출
	}
	return (dest);
}

//정수를 문자열로 변환하는 함수
char	*ft_itoa(int n)
{
	char	*dest;
	int		len;

	len = len_num(n);
	dest = (char *)malloc(sizeof(char) * (len + 1));	//문자열의 마지막에 널 문자를 고려해서 길이 + 1만큼 공간 할당
	if (dest == 0)
		return (0);
	dest = num_to_string(dest, n, len);
	return (dest);
}
