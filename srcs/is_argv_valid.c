/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_argv_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:10:07 by aumarin           #+#    #+#             */
/*   Updated: 2022/05/12 19:10:27 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_argv_valid(int argc, char **argv)
{
	size_t	i;
	int		j;

	i = 1;
	while (i < (size_t)argc)
	{
		j = 0;
		while (j < (int)ft_strlen(argv[i]))
		{
			if (argv[i][j] == '-' && j == 0)
				j++;
			if (!ft_isdigit(argv[i][j]))
				return (0);
			if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}