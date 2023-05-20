/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:55:57 by sejkim2           #+#    #+#             */
/*   Updated: 2023/05/20 20:43:12 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

//string을 int형 정수로 변환하는 함수
int	ft_atoi(const char *str)
{
	int	i;
	int	flag_minus;	//부호 판별 변수
	int	num;

	flag_minus = 1;
	i = 0;
	num = 0;
	//white space를 먼저 밀어줌
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	//그 다음에 나오는 부호에 따라 flag_minus가 1 또는 -1
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag_minus *= -1;
		i++;
	}
	//정수가 나오지 않을 때까지 자리수를 하나씩 올려가며 정수로 변환 (char - '0')
	while (str[i] >= '0' && str[i] <= '9')
		num = (num * 10) + (str[i++] - '0');
	//부호가 음수이면 -1을 곱해주고 아니면 그대로 반환하며
	//man page의 원형 함수처럼 오버플로우는 고려하지 않는다.
	if (flag_minus == -1)
		return (-1 * num);
	else
		return (num);
}
