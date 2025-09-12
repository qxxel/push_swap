/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:18:01 by agerbaud          #+#    #+#             */
/*   Updated: 2025/09/12 11:29:24 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
