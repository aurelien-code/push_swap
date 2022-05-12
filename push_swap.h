/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 22:42:30 by aumarin           #+#    #+#             */
/*   Updated: 2022/05/12 19:10:43 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/**
 *	INCLUDES
 */

# include <stdlib.h>
# include <unistd.h>
/**
 *	DEFINITIONS
 */

# ifndef STDERR
#  define STDERR 2
# endif

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

/**
 *	PROTOTYPES 
 */
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_printf(const char *str, ...);
size_t	ft_strlen(const char *s);
int		is_argv_valid(int argc, char **argv);

/** 
*	STRUCTS
*/
typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

#endif