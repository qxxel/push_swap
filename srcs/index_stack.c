/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 14:34:00 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/05 15:44:39 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_value	*min_elem(t_list *stack)
{
	t_value	*min;

	min = stack->content;
	stack = stack->next;
	while (stack)
	{
		if (((t_value *)stack->content)->value < min->value)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}

void	index_stack(t_list *stack, int size)
{
	t_value	*min;
	int		index;

	min = min_elem(stack);
	min->index = 0;
	index = 1;
	while (index < size)
	{
		min = greater_elem(min->value, stack);
		min->index = index++;
	}
}
