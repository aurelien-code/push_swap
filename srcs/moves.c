/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:03:55 by aumarin           #+#    #+#             */
/*   Updated: 2022/05/27 01:29:20 by aumarin          ###   ########.fr       */
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

int	ft_lstsize(t_stack *lst)
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

t_stack	*push(t_stack *origin, t_stack *dest)
{
	t_stack	*tmp;

	ft_printf("[1] %d\n", dest == dest->next);
	ft_printf("[2] %d\n", dest->value);
	ft_printf("[3] %d\n", ft_lstsize(dest));
	ft_printf("#######\n");
	tmp = malloc(sizeof(t_stack));
	if (!tmp)
		return (NULL);
	tmp->value = origin->value;
	if (!dest->value)
		tmp->next = NULL;
	else
		tmp->next = dest;
	*dest = *tmp;

	if (origin->next)
		*origin = *origin->next;
	else
	{
		free(tmp);
		tmp = malloc(sizeof(t_stack));
		tmp->next = NULL;
		*origin = *tmp;
	}
	free(tmp);
	return (origin);
}


/* PROBLEMS :
	CRITIK :	dest = dest->next donc boucle infinie 
*/