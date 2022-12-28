/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:05:41 by aumarin           #+#    #+#             */
/*   Updated: 2022/12/27 21:48:23 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_minimum(t_stack *stack)
{
	int	min;

	min = stack->value;
	stack = stack->next;
	while (stack)
	{
		if (min > stack->value)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	find_minimum_index(t_stack *stack)
{
	int	min;
	int	index;

	min = find_minimum(stack);
	index = 0;
	while (stack->next)
	{
		if (stack->value == min)
			return (index);
		index++;
		stack = stack->next;
	}
	return (-1);
}

int	is_in_chunk(int nbr, t_chunk *arr)
{
	int	i;

	i = 0;
	while (arr[i].value)
	{
		if (nbr == arr[i].value)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

/**
 * BUG : bug si 0 fait partie du minimum
*/
t_chunk	*find_n_minimums(t_stack *stack, int n)
{
	t_chunk		*mins;
	long		n_min;
	t_stack		*stack_head;
	int			i;

	i = -1;
	stack_head = stack;
	mins = ft_calloc(n, sizeof(t_chunk));
	if (!mins)
		return (NULL);
	while (++i < n)
	{
		stack = stack_head;
		n_min = 2147483648;
		while (stack)
		{
			if (!n_min && !is_in_chunk(stack->value, mins))
				n_min = stack->value;
			else if (stack->value < n_min && !is_in_chunk(stack->value, mins))
				n_min = stack->value;
			stack = stack->next;
		}
		mins[i].value = n_min;
	}
	return (mins);
}

int	find_x_index(int value, t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->value == value)
			return (i);
		stack = stack->next;
		i++;
	}
	return (i);
}
