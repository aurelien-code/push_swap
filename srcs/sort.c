/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 02:29:39 by aumarin           #+#    #+#             */
/*   Updated: 2022/06/19 11:47:25 by aumarin          ###   ########.fr       */
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

void	sort_small_stack(t_stack *stack, t_stack *stack_b)
{
	if (!stack)
		return ;
	push(&stack, &stack_b, 'b');
	push(&stack, &stack_b, 'b');
	while (!is_stack_sorted(stack))
	{
		if (stack->value > stack->next->value)
		{
			if (stack->value > stack->next->next->value)
			{
				stack = swap(stack, 'a');
				stack = reverse_rotate(stack);
				ft_printf("rra\n");
			}
			else if (stack->value < stack->next->next->value)
				stack = swap(stack, 'a');
			else
			{
				stack = rotate(stack);
				ft_printf("ra\n");
			}
		}
		else
		{
			if (stack->value > stack->next->next->value)
			{
				stack = reverse_rotate(stack);
				ft_printf("rra\n");
			}
			else
			{
				stack = swap(stack, 'a');
				stack = rotate(stack);
				ft_printf("ra\n");
			}
		}
		if (is_stack_sorted(stack))
		{
			push(&stack_b, &stack, 'a');
			stack = rotate(stack);
			ft_printf("ra\n");
		}
	}
	push(&stack_b, &stack, 'a');
}
