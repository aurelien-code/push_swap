/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 02:07:58 by aumarin           #+#    #+#             */
/*   Updated: 2023/01/06 20:59:21 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_chunk	*chunk_last(t_chunk *chunk)
{
	if (!chunk)
		return (NULL);
	while (chunk->next)
		chunk = chunk->next;
	return (chunk);
}

t_chunk	*new_elem(t_chunk *chunk, int value)
{
	t_chunk	*elem;

	elem = ft_calloc(1, sizeof(t_chunk));
	if (!elem)
		return (NULL);
	elem->value = value;
	if (!chunk)
		chunk = elem;
	else
		chunk_last(chunk)->next = elem;
	return (chunk);
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
