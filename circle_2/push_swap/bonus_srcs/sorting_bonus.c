/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:00:13 by sejkim2           #+#    #+#             */
/*   Updated: 2023/07/24 19:49:14 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static	int	check_is_sorted(t_stack *a, t_stack *b)
{
	t_node	*cur;

	if (b->num_of_node != 0)
		return (0);
	cur = a->top;
	while (cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}

static	int	compare_string(char *str1, char *str2)
{
	int	index;

	if (ft_strlen(str1) != ft_strlen(str2))
		return (0);
	index = 0;
	while (str1[index] && str2[index])
	{
		if (str1[index] != str2[index])
			return (0);
		index++;
	}
	return (1);
}

static	int	check_is_valid_command(char *cmd, t_stack *a, t_stack *b)
{
	if (compare_string(cmd, "sa") == 1)
		sa(a);
	else if (compare_string(cmd, "sb") == 1)
		sb(b);
	else if (compare_string(cmd, "ss") == 1)
		ss(a, b);
	else if (compare_string(cmd, "pa") == 1)
		pa(a, b);
	else if (compare_string(cmd, "pb") == 1)
		pb(a, b);
	else if (compare_string(cmd, "ra") == 1)
		ra(a);
	else if (compare_string(cmd, "rb") == 1)
		rb(b);
	else if (compare_string(cmd, "rr") == 1)
		rr(a, b);
	else if (compare_string(cmd, "rra") == 1)
		rra(a);
	else if (compare_string(cmd, "rrb") == 1)
		rrb(b);
	else if (compare_string(cmd, "rrr") == 1)
		rrr(a, b);
	else
		return (0);
	return (1);
}

static	char	*remove_newline_in_string(char *str)
{
	char	*new_str;
	int		index;
	int		str_len;

	str_len = ft_strlen(str);
	new_str = (char *)malloc(sizeof(char *) * (str_len - 1));
	if (new_str == 0)
	{
		free(str);
		return (0);
	}
	index = 0;
	while (index < str_len - 1)
	{
		new_str[index] = str[index];
		index++;
	}
	new_str[index] = '\0';
	free(str);
	return (new_str);
}

int	sorting(t_stack *a, t_stack *b)
{
	char	*cmd;

	while (1)
	{
		cmd = get_next_line(0);
		if (cmd == 0)
			break ;
		if (ft_strlen(cmd) < 2)
		{
			free(cmd);
			return (0);
		}
		cmd = remove_newline_in_string(cmd);
		if (cmd == 0)
			return (0);
		if (check_is_valid_command(cmd, a, b) == 0)
		{
			free(cmd);
			return (-1);
		}
		free(cmd);
	}
	return (check_is_sorted(a, b));
}
