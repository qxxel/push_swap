/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:33:21 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/03 11:55:52 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
