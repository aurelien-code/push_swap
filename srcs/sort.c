/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 02:29:39 by aumarin           #+#    #+#             */
/*   Updated: 2022/07/26 00:37:30 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_stack	*sort_small_stack(t_stack *stack_a)
{
	if (stack_a->value > stack_a->next->value)
	{
		if (stack_a->next->value > ft_lstlast(stack_a)->value)
		{
			swap(&stack_a, 'a');
			reverse_rotate(&stack_a, 'a');
		}
		else if (stack_a->value > ft_lstlast(stack_a)->value)
			rotate(&stack_a, 'a');
		else
			swap(&stack_a, 'a');
	}
	else
	{
		if (stack_a->value > ft_lstlast(stack_a)->value)
			reverse_rotate(&stack_a, 'a');
		else
		{
			swap(&stack_a, 'a');
			rotate(&stack_a, 'a');
		}
	}
	return (stack_a);
}

void	sort_medium_stack(t_stack *stack_a, t_stack *stack_b)
{
	while (ft_lstsize(stack_a) > 3)
		push(&stack_a, &stack_b, 'b');
	stack_a = sort_small_stack(stack_a);
	while (ft_lstsize(stack_b) > 1)
	{
		if (stack_b->value < stack_a->value)
			push(&stack_b, &stack_a, 'a');
		else
		{
			if (stack_b->value > ft_lstlast(stack_a)->value)
			{
				push(&stack_b, &stack_a, 'a');
				rotate(&stack_a, 'a');
			}
			while (stack_a->value < stack_b->value)
				reverse_rotate(&stack_a, 'a');
			push(&stack_b, &stack_a, 'a');
			while (!is_stack_sorted(stack_a))
				rotate(&stack_a, 'a');
		}
	}
	print_stack(stack_a);
}
