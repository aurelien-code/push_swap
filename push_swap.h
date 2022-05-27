/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 22:42:30 by aumarin           #+#    #+#             */
/*   Updated: 2022/05/27 15:03:32 by aumarin          ###   ########.fr       */
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
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_printf(const char *str, ...);
size_t	ft_strlen(const char *s);
t_stack	*ft_lstlast(t_stack *lst);
int		ft_lstsize(t_stack *lst);
int		is_argv_valid(int argc, char **argv);
t_stack	*init_stack(int size, char **numbers);
void	print_stack(t_stack *lst);
t_stack	*swap(t_stack *head);
t_stack	*rotate(t_stack *head);
t_stack	*reverse_rotate(t_stack *head);
t_stack	*push(t_stack **origin, t_stack **dest);

#endif