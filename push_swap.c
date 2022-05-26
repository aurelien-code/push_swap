/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:16:41 by aumarin           #+#    #+#             */
/*   Updated: 2022/05/26 02:26:07 by aumarin          ###   ########.fr       */
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
		ft_printf("---INIT----\n");
		print_stack(head_a);
		ft_printf("---SWAP----\n");
		head_a = swap(head_a);
		print_stack(head_a);
		ft_printf("---ROTA----\n");
		head_a = rotate(head_a);
		print_stack(head_a);
		ft_printf("---ATOR----\n");
		head_a = reverse_rotate(head_a);
		print_stack(head_a);
	}
	return (0);
}

/** 
	Bugs :
		- Numbers bigger than int doesnt generate an error !
*/