/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chunks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:34:46 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/05 15:42:39 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static bool	in_chunk(t_list *stack, int min, int max)
{
	int	index;

	index = ((t_value *)stack->content)->index;
	return (min <= index && index < max);
}

static t_operation	get_rotation(t_list *stack, int min, int max)
{
	int	rotations;
	int	reverse_rotations;

	if (!(stack && stack->next && stack->next->next && stack->next->next->next))
		return (NULL);
	rotations = 0;
	while (stack && !in_chunk(stack, min, max))
	{
		rotations++;
		stack = stack->next;
	}
	if (!stack)
		return (NULL);
	if (!rotations)
		return (rotate_a);
	while (stack)
	{
		if (in_chunk(stack, min, max))
			reverse_rotations = 0;
		reverse_rotations++;
		stack = stack->next;
	}
	if (reverse_rotations < rotations)
		return (reverse_rotate_a);
	return (rotate_a);
}

void	create_chunks(int size, t_stack stacks)
{
	int			current;
	int			min;
	int			max;
	t_operation	rotation;

	current = 0;
	while (current < 3)
	{
		min = current * size;
		max = ++current * size;
		rotation = get_rotation(*stacks.a, min, max);
		while (rotation)
		{
			while (!in_chunk(*stacks.a, min, max))
				rotation(stacks);
			push_b(stacks);
			rotation = get_rotation(*stacks.a, min, max);
		}
	}
}
