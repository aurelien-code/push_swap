/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 02:29:39 by aumarin           #+#    #+#             */
/*   Updated: 2023/01/07 02:16:38 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*sort_small_stack(t_stack *stack_a)
{
	if (is_stack_sorted(stack_a))
		return (stack_a);
	if (stack_a->value > stack_a->next->value)
	{
		if (stack_a->next->value > stack_last(stack_a)->value)
		{
			swap(&stack_a, 'a');
			reverse_rotate(&stack_a, 'a');
		}
		else if (stack_a->value > stack_last(stack_a)->value)
			rotate(&stack_a, 'a');
		else
			swap(&stack_a, 'a');
	}
	else
	{
		if (stack_a->value > stack_last(stack_a)->value)
			reverse_rotate(&stack_a, 'a');
		else
		{
			swap(&stack_a, 'a');
			rotate(&stack_a, 'a');
		}
	}
	return (stack_a);
}

t_stack	*sort_medium_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	min;

	min = find_minimum(stack_a);
	while (stack_size(stack_a) > 3)
	{
		if (min == stack_a->value)
		{
			push(&stack_a, &stack_b, 'b');
			min = find_minimum(stack_a);
		}
		else if (find_x_index(min, stack_a) > 3)
			reverse_rotate(&stack_a, 'a');
		else
			rotate(&stack_a, 'a');
	}
	stack_a = sort_small_stack(stack_a);
	while (stack_size(stack_b) > 1)
	{
		push(&stack_b, &stack_a, 'a');
		if (stack_a->value > stack_a->next->value)
			swap(&stack_a, 'a');
	}
	return (stack_a);
}

t_stack	*sort_big_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_chunk	*chunk;
	int		size;
	int		i;

	chunk = find_n_minimums(stack_a, stack_size(stack_a));
	stack_a = set_sorted_idx(stack_a, chunk);
	i = 1;
	while (!is_stack_sorted(stack_a))
	{
		size = stack_size(stack_a);
		while (size > 0)
		{
			if (stack_a->sorted_index & i)
				rotate(&stack_a, 'a');
			else
				push(&stack_a, &stack_b, 'b');
			size--;
		}
		i = i << 1;
		while (stack_size(stack_b) > 1)
			push(&stack_b, &stack_a, 'a');
	}
	free_chunk(chunk);
	return (stack_a);
}
