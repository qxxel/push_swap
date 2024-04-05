/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:18:01 by agerbaud          #+#    #+#             */
/*   Updated: 2024/04/05 16:32:36 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap(t_list **stack)
{
	t_list	*start;

	if (!*stack || !(*stack)->next)
		return ;
	start = (*stack)->next;
	(*stack)->next = start->next;
	ft_lstadd_front(stack, start);
}

void	swap_a(t_stack stacks)
{
	ft_putstr_fd("sa\n", 1);
	swap(stacks.a);
}

void	swap_b(t_stack stacks)
{
	ft_putstr_fd("sb\n", 1);
	swap(stacks.b);
}

void	swap_stacks(t_stack stacks)
{
	ft_putstr_fd("ss\n", 1);
	swap(stacks.a);
	swap(stacks.b);
}
