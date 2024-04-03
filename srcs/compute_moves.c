/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:49:16 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/03 11:55:52 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	compute_b_moves(t_list *stack, int position, t_instructions *moves)
{
	int	reverse;

	reverse = 0;
	while (stack)
	{
		reverse++;
		stack = stack->next;
	}
	if (position < reverse)
	{
		moves->rb = position;
		moves->rrb = false;
	}
	else
	{
		moves->rb = reverse;
		moves->rrb = true;
	}
}

static void	compute_a_moves(int value, t_list *stack, t_instructions *moves)
{
	t_value	*elem;
	int		reverse;

	elem = greater_elem(value, stack);
	moves->ra = 0;
	moves->rra = false;
	if (!elem)
		return ;
	while (stack->content != elem)
	{
		moves->ra++;
		stack = stack->next;
	}
	reverse = 0;
	while (stack)
	{
		reverse++;
		stack = stack->next;
	}
	if (reverse < moves->ra || (reverse == moves->ra && moves->rrb))
	{
		moves->ra = reverse;
		moves->rra = true;
	}
}

static int	sum_moves(t_instructions moves)
{
	if (moves.rra != moves.rrb)
		return (moves.ra + moves.rb);
	if (moves.ra > moves.rb)
		return (moves.ra);
	return (moves.rb);
}

t_instructions	compute_moves(t_list *stack, t_stack stacks, int position)
{
	t_instructions	moves;
	t_instructions	next_instructions;

	compute_b_moves(stack, position, &moves);
	compute_a_moves(((t_value *)stack->content)->value, *stacks.a, &moves);
	moves.sum = sum_moves(moves);
	if (!stack->next)
		return (moves);
	next_instructions = compute_moves(stack->next, stacks, position + 1);
	if (moves.sum > next_instructions.sum)
		return (next_instructions);
	return (moves);
}
