/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:05:41 by aumarin           #+#    #+#             */
/*   Updated: 2022/08/14 16:49:39 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_minimum(t_stack *stack)
{
	int	min;

	min = stack->value;
	stack = stack->next;
	while (stack->next)
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
