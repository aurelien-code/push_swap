/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:47:01 by aumarin           #+#    #+#             */
/*   Updated: 2023/01/07 00:47:20 by aumarin          ###   ########.fr       */
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

void	free_split(char **splitted)
{
	int	i;

	i = -1;
	while (splitted[++i])
		free(splitted[i]);
	if (splitted[i])
		free(splitted[i]);
	if (splitted)
		free(splitted);
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
	if (argc == 2)
		free_split(splitted);
	return (head);
}

void	print_stack(t_stack *head)
{
	int	i;

	i = 0;
	if (!head)
		return ;
	while (head)
	{
		ft_printf("val = %d ;", head->value);
		ft_printf(" idx = %d\n", head->sorted_index);
		head = head->next;
		i++;
	}
}
