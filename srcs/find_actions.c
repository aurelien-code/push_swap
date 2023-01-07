/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:05:41 by aumarin           #+#    #+#             */
/*   Updated: 2023/01/06 22:31:39 by aumarin          ###   ########.fr       */
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

int	is_in_chunk(int nbr, t_chunk *chunk)
{
	while (chunk)
	{
		if (nbr == chunk->value)
			return (1);
		chunk = chunk->next;
	}
	return (0);
}

t_chunk	*find_n_minimums(t_stack *stack, int n)
{
	t_chunk		*mins;
	long		n_min;
	t_stack		*stack_head;
	int			i;

	i = -1;
	stack_head = stack;
	mins = ft_calloc(1, sizeof(t_chunk));
	while (++i < n && mins)
	{
		stack = stack_head;
		n_min = ABS_INT_MIN;
		while (stack)
		{
			if (stack->value < n_min && !is_in_chunk(stack->value, mins))
				n_min = stack->value;
			stack = stack->next;
		}
		if (i != 0)
			mins = new_elem(mins, n_min);
		else
			mins->value = n_min;
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
