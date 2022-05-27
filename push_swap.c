/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:16:41 by aumarin           #+#    #+#             */
/*   Updated: 2022/05/27 15:38:35 by aumarin          ###   ########.fr       */
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
		ft_printf("Args : ok\n");
		head_a = init_stack(argc, argv);
		head_b = malloc(sizeof(t_stack));
		if (!head_b)
			return (1);
		head_b->next = NULL;
		ft_printf("---INIT----\n");
		print_stack(head_a);
	}
	return (0);
}

/** 
	Bugs :
		- Numbers bigger than int doesnt generate an error !
*/