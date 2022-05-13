/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:47:01 by aumarin           #+#    #+#             */
/*   Updated: 2022/05/13 16:50:50 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(int size, char **numbers)
{
	int		i;
	t_stack	*head;
	t_stack	*previous;
	t_stack	*current;

	i = 1;
	head = NULL;
	previous = NULL;
	current = NULL;
	while (i < size)
	{
		current = malloc(sizeof(t_stack));
		if (!current)
			return (NULL);
		current->value = ft_atoi(numbers[i]);
		current->next = NULL;
		if (previous)
			previous->next = current;
		previous = current;
		if (i == 1)
			head = current;
		i++;
	}
	return (head);
}

void	print_stack(t_stack *head)
{
	int	i;

	i = 0;
	if (!head)
		return ;
	while (head->next != NULL)
	{
		ft_printf("[%d] %d\n", i,  head->value);
		head = head->next;
		i++;
	}
	ft_printf("[.] %d\n", head->value);
}
