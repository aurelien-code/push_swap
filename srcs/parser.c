/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 02:07:27 by aumarin           #+#    #+#             */
/*   Updated: 2022/12/14 16:33:00 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i < argc)
	{
		while (i + j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[i + j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_int_limits(char *num)
{
	if (ft_big_atoi(num) > ft_big_atoi(INT_MAX_STR))
		return (0);
	else if (ft_big_atoi(num) < ft_big_atoi(INT_MIN_STR))
		return (0);
	else
		return (1);
}

int	check_args(int argc, char **argv)
{
	size_t	i;
	int		j;

	i = 0;
	while (i < (size_t)argc)
	{
		j = 0;
		while (j < (int)ft_strlen(argv[i]))
		{
			if (argv[i][j] == '-' && j == 0)
				j++;
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		if (!check_int_limits(argv[i]))
			return (0);
		i++;
	}
	if (!check_duplicate(argc, argv))
		return (0);
	return (1);
}

int	is_argv_valid(int argc, char **argv)
{
	char	**splitted;
	size_t	args_count;
	int		result;

	result = 0;
	args_count = 1;
	if (argc == 2)
	{
		args_count = 0;
		splitted = ft_split(argv[1], ' ');
		if (!splitted)
			return (0);
		while (splitted[args_count])
			args_count++;
		result = check_args(args_count, splitted);
		args_count = -1;
		while (splitted[++args_count])
			free(splitted[args_count]);
		free(splitted[args_count]);
		free(splitted);
		return (result);
	}
	else
		return (check_args(argc, argv + 1));
}
