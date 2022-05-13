/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:16:41 by aumarin           #+#    #+#             */
/*   Updated: 2022/05/13 16:51:52 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*head_a;

	head_a = NULL;
	if (argc < 2)
		return (1);
	else if (!is_argv_valid(argc, argv))
		write(STDERR, "Error\n", 6);
	else
	{
		ft_printf("Args : ok\n");
		head_a = init_stack(argc, argv);
		print_stack(head_a);
	}
	return (0);
}

/** 
	Bugs :
		- Numbers bigger than int doesnt generate an error !
*/