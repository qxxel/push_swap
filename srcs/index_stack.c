/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 14:34:00 by agerbaud          #+#    #+#             */
/*   Updated: 2025/09/12 11:29:24 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
