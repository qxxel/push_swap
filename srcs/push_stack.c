/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:33:21 by agerbaud          #+#    #+#             */
/*   Updated: 2025/09/12 11:29:24 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push(t_list **src, t_list **dst)
{
	t_list	*new;

	if (!*src)
		return ;
	new = *src;
	*src = (*src)->next;
	ft_lstadd_front(dst, new);
}

void	push_a(t_stack stacks)
{
	ft_putstr_fd("pa\n", 1);
	push(stacks.b, stacks.a);
}

void	push_b(t_stack stacks)
{
	ft_putstr_fd("pb\n", 1);
	push(stacks.a, stacks.b);
}
