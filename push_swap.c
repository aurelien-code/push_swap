/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:16:41 by aumarin           #+#    #+#             */
/*   Updated: 2022/04/25 23:40:02 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "string.h"
#include <limits.h>

int	main(int argc, char **argv)
{
	size_t	i;
	int		j;

	if (argc < 2)
		return (1);
	else
	{
		i = 1;
		while ((int)i < argc)
		{
			j = 0;
			while (j < (int)strlen(argv[i]))
			{
				if (!ft_isdigit(argv[i][j]) || (ft_atoi(argv[i]) >= INT_MAX  || ft_atoi(argv[i]) >= INT_MIN))
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
		- fix : negatives numbers generate an error
		- fix : ligne trop longue
		- todo : change strlen to ft_strlen at multiple places
		- todo : change limit.h with personnal declarations
*/