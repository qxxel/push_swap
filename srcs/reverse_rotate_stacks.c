/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_stacks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 15:19:04 by agerbaud          #+#    #+#             */
/*   Updated: 2025/09/12 11:29:24 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	reverse_rotate(t_list **stack)
{
	t_list	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next->next)
		last = last->next;
	ft_lstadd_front(stack, last->next);
	last->next = NULL;
}

void	reverse_rotate_a(t_stack stacks)
{
	ft_putstr_fd("rra\n", 1);
	reverse_rotate(stacks.a);
}

void	reverse_rotate_b(t_stack stacks)
{
	ft_putstr_fd("rrb\n", 1);
	reverse_rotate(stacks.b);
}

void	reverse_rotate_stacks(t_stack stacks)
{
	ft_putstr_fd("rrr\n", 1);
	reverse_rotate(stacks.a);
	reverse_rotate(stacks.b);
}
