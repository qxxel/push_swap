/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:26:57 by agerbaud          #+#    #+#             */
/*   Updated: 2024/01/12 10:28:35 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"



void	ft_swap(t_stack *stack_a, t_stack *stack_b, int target)
{
	if ((target == 1 || target == 3) && ft_lstcount(stack_a) >= 2)
	{
		
	}
	if ((target == 2 || target == 3) && ft_lstcount(stack_b) >= 2)
	{

	}
}

void	ft_push(t_stack *stack_a, t_stack *stack_b, int target)
{
	if (target == 1 && ft_lstcount(stack_b) >= 1)
	{

	}
	if (target == 2 && ft_lstcount(stack_a) >= 1)
	{

	}
}

void	ft_rotate(t_stack *stack_a, t_stack *stack_b, int target)
{
	if ((target == 1 || target == 3) && ft_lstcount(stack_a) >= 2)
	{

	}
	if ((target == 2 || target == 3) && ft_lstcount(stack_b) >= 2)
	{

	}
}

void	ft_reverse_rotate(t_stack *stack_a, t_stack *stack_b, int target)
{
	if ((target == 1 || target == 3) && ft_lstcount(stack_b) >= 2)
	{

	}
	if ((target == 2 || target == 3) && ft_lstcount(stack_b) >= 2)
	{

	}
}
