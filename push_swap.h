/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 22:42:30 by aumarin           #+#    #+#             */
/*   Updated: 2022/12/14 12:09:53 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/**
 *	INCLUDES
 */

# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
/**
 *	DEFINITIONS
 */

# ifndef STDERR
#  define STDERR 2
# endif

# ifndef INT_MAX
#  define INT_MAX 2147483647
#  define INT_MAX_STR "2147483647"
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
#  define INT_MIN_STR "-2147483648"
# endif

# define ERROR_MSG "Error\n"

/** 
*	STRUCTS
*/
typedef struct s_stack
{
	int				value;
	struct s_stack	*previous;
	struct s_stack	*next;
}	t_stack;

/**
 *	PROTOTYPES 
 */

/**	srcs	*/
int		is_argv_valid(int argc, char **argv);
t_stack	*init_stack(int size, char **numbers);
void	print_stack(t_stack *lst);
int		is_stack_sorted(t_stack *stack);
int		find_minimum(t_stack *stack);
int		find_minimum_index(t_stack *stack);
int		is_stack_sorted(t_stack *stack);

/**	moves	*/
void	swap(t_stack **stack, char move);
void	rotate(t_stack	**stack, char move);
void	reverse_rotate(t_stack **stack, char move);
void	push(t_stack **origin, t_stack **dest, char move);

/**	sort	*/
t_stack	*sort_small_stack(t_stack *stack_a);
void	sort_medium_stack(t_stack *stack_a, t_stack *stack_b);

int		stack_size(t_stack *lst);
t_stack	*stack_last(t_stack *lst);

#endif