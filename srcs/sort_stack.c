/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:20:56 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/05 15:55:58 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static bool	swap_three(t_list *stack)
{
	int	first;
	int	second;
	int	third;

	first = ((t_value *)stack->content)->value;
	second = ((t_value *)stack->next->content)->value;
	third = ((t_value *)stack->next->next->content)->value;
	return ((first < third
		&& ((first < second && first < third && second > third)
		|| (first > second && second < third)))
		|| (first > second && second > third));
}

static void	do_b_rotations(t_instructions *moves, t_stack stacks)
{
	t_operation	rotation;

	if (moves->rra == moves->rrb)
	{
		if (moves->rra)
			rotation = reverse_rotate_stacks;
		else
			rotation = rotate_stacks;
		while (moves->ra && moves->rb)
		{
			rotation(stacks);
			moves->ra--;
			moves->rb--;
		}
	}
	if (moves->rrb)
		rotation = reverse_rotate_b;
	else
		rotation = rotate_b;
	while (moves->rb--)
		rotation(stacks);
}

static t_operation	final_rotation(t_list *stack)
{
	int	rotations;
	int	reverse_rotations;

	rotations = 0;
	while (((t_value *)stack->content)->index != 0)
	{
		rotations++;
		stack = stack->next;
	}
	reverse_rotations = 0;
	while (stack)
	{
		reverse_rotations++;
		stack = stack->next;
	}
	if (reverse_rotations < rotations)
		return (reverse_rotate_a);
	return (rotate_a);
}

void	sort_stack(t_stack stacks, int size)
{
	t_instructions	moves;
	t_operation		rotation;

	if (size == 2)
		return (swap_a(stacks));
	index_stack(*stacks.a, size);
	create_chunks(size / 3, stacks);
	if (swap_three(*stacks.a))
		swap_a(stacks);
	while (*stacks.b)
	{
		moves = compute_moves(*stacks.b, stacks, 0);
		do_b_rotations(&moves, stacks);
		if (moves.rra)
			rotation = reverse_rotate_a;
		else
			rotation = rotate_a;
		while (moves.ra--)
			rotation(stacks);
		push_a(stacks);
	}
	rotation = final_rotation(*stacks.a);
	while (((t_value *)(*stacks.a)->content)->index != 0)
		rotation(stacks);
}
