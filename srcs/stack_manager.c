/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:47:01 by aumarin           #+#    #+#             */
/*   Updated: 2022/12/14 16:04:08 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_stack_elem(t_stack *head, int value)
{
	t_stack	*elem;

	elem = ft_calloc(1, sizeof(t_stack));
	if (!elem)
		return (NULL);
	elem->value = value;
	if (stack_last(head))
	{
		stack_last(head)->next = elem;
		elem->previous = stack_last(head);
	}
	if (!head)
		head = elem;
	return (elem);
}

t_stack	*init_stack(int argc, char **argv)
{
	char	**splitted;
	int		i;
	t_stack	*head;
	t_stack	*stack;

	i = -1;
	head = NULL;
	splitted = argv + 1;
	if (argc == 2)
		splitted = ft_split(argv[1], ' ');
	while (splitted[++i])
	{
		stack = new_stack_elem(head, ft_atoi(splitted[i]));
		if (!stack)
			return (NULL);
		if (!head)
			head = stack;
	}
	i = -1;
	while (argc == 2 && splitted[++i])
		free(splitted[i]);
	free(splitted[i]);
	free(splitted);
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
		ft_printf("->	%d\n", head->value);
		head = head->next;
		i++;
	}
	if (head->value)
		ft_printf("->	%d\n", head->value);
}
