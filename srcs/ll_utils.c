/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:40:11 by aumarin           #+#    #+#             */
/*   Updated: 2023/01/07 00:45:40 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_last(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int	stack_size(t_stack *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 1;
	while (lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}


t_stack	*set_sorted_idx(t_stack *stack, t_chunk *chunk)
{
	t_stack	*head;
	int		i;

	i = 0;
	head = stack;
	while (chunk)
	{
		stack = head;
		while (stack)
		{
			if (stack->value == chunk->value)
				stack->sorted_index = i;
			stack = stack->next;
		}
		i++;
		chunk = chunk->next;
	}
	stack = head;
	return (stack);
}
