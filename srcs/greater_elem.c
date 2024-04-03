/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greater_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:35:23 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/03 11:55:52 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_value	*greater_elem(int value, t_list *stack)
{
	t_value	*elem;

	while (stack && ((t_value *)stack->content)->value <= value)
		stack = stack->next;
	if (!stack)
		return (NULL);
	elem = stack->content;
	stack = stack->next;
	while (stack)
	{
		if (((t_value *)stack->content)->value < elem->value
			&& ((t_value *)stack->content)->value > value)
			elem = stack->content;
		stack = stack->next;
	}
	return (elem);
}
