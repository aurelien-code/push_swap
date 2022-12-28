/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 02:07:58 by aumarin           #+#    #+#             */
/*   Updated: 2022/12/28 12:47:08 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_update_moves(t_chunk *chunk, t_stack *stack)
{
	int	s_size;

	while (chunk)
	{
		s_size = stack_size(stack);
		chunk->rr_moves = s_size - find_x_index(chunk->value, stack);
		chunk->r_moves = find_x_index(chunk->value, stack);
		chunk = chunk->next;
	}
}

t_chunk	*create_chunk(t_stack *stack)
{
	t_chunk	*chunk;

	if (stack_size(stack) < 5)
		chunk = find_n_minimums(stack, stack_size(stack));
	else
		chunk = find_n_minimums(stack, 5);
	if (!chunk)
		return (NULL);
	chunk_update_moves(chunk, stack);
	return (chunk);
}

void	push_chunk(t_chunk *chunk, t_stack **stack_a, t_stack **stack_b)
{
	int	moves_count;

	while (chunk)
	{
		moves_count = -1;
		if (chunk->r_moves < chunk->rr_moves)
		{
			while (++moves_count < chunk->r_moves)
				rotate(stack_a, 'a');
		}
		else
		{
			while (++moves_count < chunk->rr_moves)
				reverse_rotate(stack_a, 'a');
		}
		push(stack_a, stack_b, 'b');
		chunk = chunk->next;
		chunk_update_moves(chunk, *stack_a);
	}
}

void	free_chunk(t_chunk *chunk)
{
	t_chunk	*tmp;

	while (chunk)
	{
		tmp = chunk;
		chunk = chunk->next;
		if (tmp)
			free(tmp);
	}
	if (chunk)
		free(chunk);
}
