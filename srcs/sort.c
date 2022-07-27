/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 02:29:39 by aumarin           #+#    #+#             */
/*   Updated: 2022/07/26 19:14:44 by aumarin          ###   ########.fr       */
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

int	is_top_minimum(t_stack *stack)
{
	int	min;

	min = stack->value;
	while (stack->next)
	{
		if (min > stack->value)
			return (0);
		else
			stack = stack->next;
	}
	ft_printf("MINIMUM -> %d\n", min);
	return (1);
}

void	sort_medium_stack(t_stack *stack_a, t_stack *stack_b)
{
	while (ft_lstsize(stack_a) > 3)
	{
		if (is_top_minimum(stack_a))
			push(&stack_a, &stack_b, 'b');
		else
			reverse_rotate(&stack_a, 'a');
	}
	ft_printf("STACKB\n");
	print_stack(stack_b);
	stack_a = sort_small_stack(stack_a);
	while (ft_lstsize(stack_b) > 1)
	{
		push(&stack_b, &stack_a, 'a');
	}
	print_stack(stack_a);
}
