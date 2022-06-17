/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 02:29:39 by aumarin           #+#    #+#             */
/*   Updated: 2022/06/17 16:47:18 by aumarin          ###   ########.fr       */
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
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			push(&stack, &stack_b, 'a');
		else if (stack->value == stack->next->value)
			push(&stack, &stack_b, 'a');
		else
			stack = swap(stack, 'a');
	}
	push(&stack, &stack_b, 'a');
}
