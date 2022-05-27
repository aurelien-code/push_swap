/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:03:55 by aumarin           #+#    #+#             */
/*   Updated: 2022/05/27 15:35:26 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*swap(t_stack *head)
{
	t_stack	*second;

	second = head->next;
	head->next = second->next;
	second->next = head;
	return (second);
}

t_stack	*rotate(t_stack *head)
{
	t_stack	*last;
	t_stack	*second;

	second = head->next;
	last = ft_lstlast(head);
	last->next = head;
	head->next = NULL;
	return (second);
}

t_stack	*reverse_rotate(t_stack *head)
{
	t_stack	*last;

	last = ft_lstlast(head);
	last->next = head;
	while (head->next != last)
		head = head->next;
	head->next = NULL;
	return (last);
}

t_stack	*push(t_stack **origin, t_stack **dest)
{
	t_stack	*tmp;

	tmp = malloc(sizeof(t_stack));
	if (!tmp)
		return (NULL);
	tmp->value = origin[0]->value;
	if (*dest)
		tmp->next = *dest;
	else
		tmp->next = NULL;
	*dest = tmp;
	if (origin[0]->next != NULL)
		*origin = origin[0]->next;
	else
		*origin = NULL;
	return (*dest);
}


/* PROBLEMS :
	CRITIK :	dest = dest->next donc boucle infinie 
*/