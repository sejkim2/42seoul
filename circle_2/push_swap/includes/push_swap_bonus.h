/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 18:49:12 by sejkim2           #+#    #+#             */
/*   Updated: 2023/07/22 18:49:13 by sejkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../mylib/includes/ft_printf.h"
# include "../mylib/includes/get_next_line.h"
# include "../mylib/includes/libft.h"
# include <stdlib.h>

# define MAX_VALUE 2147483647
# define MIN_VALUE -2147483648

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int				value;
	int				count_rr;
	int				count_rrr;
	int				count_ra;
	int				count_rb;
	int				count_rra;
	int				count_rrb;
}	t_node;

typedef struct s_stack_base_list
{
	struct s_node	*top;
	struct s_node	*tail;
	struct s_node	*max_node;
	struct s_node	*min_node;
	int				num_of_node;
}	t_stack;

int			main(int argc, char **argv);

long long	*parsing_argument(int argc, char **argv, int *word_count);
long long	*change_string_to_num(int num_size, int argc, char **argv);
void		check_integer_and_duplicate(long long *num_arr, int word_count);
t_stack		*make_stack(char stack_name, int size_arr, long long *num_arr);
t_stack		*free_stack(t_stack *stack);
void		check_memory_error_in_change_string_to_num(long long *num_arr);

void		run_push_swap(t_stack **a, t_stack **b);
int			sorting(t_stack *a, t_stack *b);

void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stack *a, t_stack *b);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		ra(t_stack *a);
void		rb(t_stack *b);
void		rr(t_stack *a, t_stack *b);
void		rra(t_stack *a);
void		rrb(t_stack *b);
void		rrr(t_stack *a, t_stack *b);

#endif