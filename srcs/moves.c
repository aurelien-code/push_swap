/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:03:55 by aumarin           #+#    #+#             */
/*   Updated: 2022/12/20 14:38:55 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Swap the first 2 elements at the top of stack.
	Do nothing if there is only one or no elements
*/
void	swap(t_stack **stack, char move)
{
	int	tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
	ft_printf("s%c\n", move);
}

void	rotate(t_stack	**stack, char move)
{
	t_stack	*last;
	t_stack	*second;

	last = stack_last(*stack);
	second = (*stack)->next;
	(*stack)->next = NULL;
	(*stack)->previous = last;
	second->previous = NULL;
	last->next = *stack;
	(*stack) = second;
	ft_printf("r%c\n", move);
}

void	reverse_rotate(t_stack **stack, char move)
{
	t_stack	*last;

	last = stack_last(*stack);
	last->next = *stack;
	while ((*stack)->next != last)
		*stack = (*stack)->next;
	(*stack)->next = NULL;
	(*stack) = last;
	ft_printf("rr%c\n", move);
}

void	push(t_stack **origin, t_stack **dest, char move)
{
	t_stack	*tmp;

	tmp = ft_calloc(1, sizeof(t_stack));
	if (!tmp)
		return ;
	tmp->value = (*origin)->value;
	if (*dest)
	{
		tmp->next = *dest;
		(*dest)->previous = tmp;
	}
	else
		tmp->next = NULL;
	*dest = tmp;
	if ((*origin)->next != NULL)
	{
		tmp = (*origin)->next;
		free(*origin);
		*origin = tmp;
	}
	else
		*origin = NULL;
	ft_printf("p%c\n", move);
}
