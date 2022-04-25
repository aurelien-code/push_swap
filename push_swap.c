/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:16:41 by aumarin           #+#    #+#             */
/*   Updated: 2022/04/25 23:23:06 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "string.h"

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 2)
		return (1);
	else
	{
		i = 1;
		while (i < argc)
		{
			j = 0;
			while (j < (int)strlen(argv[i]))
			{
				if (ft_isdigit((int)argv[i][j]) == 0)
				{
					write(STDERR, "Error\n", 6);
					return (1);
				}
				j++;
			}
			i++;
		}	
		ft_printf("lets go");
	}
	return (0);
}

/**
	REMINDER
		- fix : ft_strlen duplicate (so relink)
*/