/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:16:41 by aumarin           #+#    #+#             */
/*   Updated: 2022/07/25 17:55:43 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*head_a;
	t_stack	*head_b;

	head_b = NULL;
	head_a = NULL;
	if (argc < 2)
		return (1);
	else if (!is_argv_valid(argc, argv))
		write(STDERR, "Error\n", 6);
	else
	{
		head_a = init_stack(argc, argv);
		if (is_stack_sorted(head_a))
			return (0);
		head_b = malloc(sizeof(t_stack));
		if (!head_b)
			return (1);
		head_b->next = NULL;
		if (ft_lstsize(head_a) < 4)
			sort_small_stack(head_a);
	}
	return (0);
}

/** 
	Bugs :
		- Numbers bigger than int doesnt generate an error !
*/