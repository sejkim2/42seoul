/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:57:30 by sejkim2           #+#    #+#             */
/*   Updated: 2023/03/22 14:25:48 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//itoa 함수를 사용하면 동적 할당이 되기 때문에 free 책임을 지게 되므로 메모리를 정적으로 할당함

void	print(char *ar, int max_index, int fd)
{
	int	i;
	int	print_num;

	i = max_index - 1;
	while (i >= 0)
	{
		print_num = ar[i--] + 48;
		write(fd, &print_num, 1);
	}
}

int	check_sign(int n, int fd)
{
	int	r;

	if (n < 0)
	{
		r = (-1) * n;
		write(fd, "-", 1);		//음수이면 음수 출력 후 양수로 변환 (나눗셈 연산 고려)
	}
	else
		r = n;
	return (r);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		r;
	char	print_num[10];		//정수형의 최대 크기를 고려한 크기 할당
	int		index;

	index = 0;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);		//오버플로우 방지를 위한 예외처리
	else if (n == 0)
		write(fd, "0", 1);
	else
	{
		r = check_sign(n, fd);
		while (r > 0)
		{
			print_num[index++] = r % 10;		//역순으로 배열에 저장하여 나중에 다시 역순 출력
			r = r / 10;
		}
		print(print_num, index, fd);
	}
}
