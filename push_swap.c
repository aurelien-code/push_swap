/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:16:41 by aumarin           #+#    #+#             */
/*   Updated: 2022/12/14 16:27:27 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack->next)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
	if (stack)
		free(stack);
}

int	main(int argc, char **argv)
{
	t_stack	*head_a;
	t_stack	*head_b;

	head_b = NULL;
	head_a = NULL;
	if (argc < 2)
		return (1);
	else if (!is_argv_valid(argc, argv))
		ft_putstr_fd(ERROR_MSG, STDERR);
	else
	{
		head_a = init_stack(argc, argv);
		if (!is_stack_sorted(head_a))
		{
			print_stack(head_a);
			free_stack(head_a);
			return (0);
		}
		head_b = malloc(sizeof(t_stack));
		if (!head_b)
			return (1);
		head_b->next = NULL;
		if (stack_size(head_a) < 4)
			sort_small_stack(head_a);
		else if (stack_size(head_a) < 6)
			sort_medium_stack(head_a, head_b);
		free_stack(head_a);

	}
	return (0);
}
