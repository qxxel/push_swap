/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:51:57 by agerbaud          #+#    #+#             */
/*   Updated: 2024/04/05 16:32:36 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	is_sorted_stack(t_list *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (((t_value *)stack->content)->value
			> ((t_value *)stack->next->content)->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}
