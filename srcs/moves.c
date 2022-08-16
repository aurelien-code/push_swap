/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:03:55 by aumarin           #+#    #+#             */
/*   Updated: 2022/08/16 16:15:44 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, char move)
{
	t_stack	*tmp;

	tmp = malloc(sizeof(t_stack));
	if (!tmp)
		return ;
	tmp->value = (*stack)->value;
	tmp->next = (*stack)->next->next;
	*stack = (*stack)->next;
	(*stack)->next = tmp;
	ft_printf("s%c\n", move);
}

void	rotate(t_stack	**stack, char move)
{
	t_stack	*last;
	t_stack	*second;

	last = ft_lstlast(*stack);
	second = (*stack)->next;
	(*stack)->next = NULL;
	last->next = *stack;
	(*stack) = second;
	ft_printf("r%c\n", move);
}

void	reverse_rotate(t_stack **stack, char move)
{
	t_stack	*last;

	last = ft_lstlast(*stack);
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

	tmp = malloc(sizeof(t_stack));
	if (!tmp)
		return ;
	tmp->value = (*origin)->value;
	if (*dest)
		tmp->next = *dest;
	else
		tmp->next = NULL;
	*dest = tmp;
	if ((*origin)->next != NULL)
		*origin = (*origin)->next;
	else
		*origin = NULL;
	ft_printf("p%c\n", move);
}
