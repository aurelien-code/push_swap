/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 22:42:30 by aumarin           #+#    #+#             */
/*   Updated: 2023/01/07 03:15:43 by aumarin          ###   ########.fr       */
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
# define ABS_INT_MIN 2147483648

/** 
*	STRUCTS
*/
typedef struct s_stack
{
	int				value;
	int				sorted_index;
	struct s_stack	*previous;
	struct s_stack	*next;
}	t_stack;

typedef struct s_chunk
{
	int				value;
	struct s_chunk	*next;
}	t_chunk;

/**
 *	PROTOTYPES 
 */

/*	checker.c */
int		is_stack_sorted(t_stack *stack);

/*	chunk.c */
t_chunk	*chunk_last(t_chunk *chunk);
t_chunk	*new_elem(t_chunk *chunk, int value);
void	free_chunk(t_chunk *chunk);

/*	find_actions.c */
int		find_minimum(t_stack *stack);
t_chunk	*find_n_minimums(t_stack *stack, int n);
int		find_x_index(int value, t_stack *stack);

/*	ll_utils.c */
t_stack	*stack_last(t_stack *lst);
int		stack_size(t_stack *lst);
t_stack	*set_sorted_idx(t_stack *stack, t_chunk *chunk);

/*	moves.c */
void	swap(t_stack **stack, char move);
void	rotate(t_stack	**stack, char move);
void	reverse_rotate(t_stack **stack, char move);
void	push(t_stack **origin, t_stack **dest, char move);

/*	parser.c */
int		is_argv_valid(int argc, char **argv);

/*	sort.c */
t_stack	*sort_small_stack(t_stack *stack_a);
t_stack	*sort_medium_stack(t_stack *stack_a, t_stack *stack_b);
t_stack	*sort_big_stack(t_stack *stack_a, t_stack *stack_b);

/*	stack_manager.c */
void	free_stack(t_stack *stack);
t_stack	*init_stack(int size, char **numbers);

#endif