/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:00:57 by agerbaud          #+#    #+#             */
/*   Updated: 2024/04/05 16:32:36 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_stacks(t_stack stacks)
{
	ft_lstclear(stacks.a, free);
	ft_lstclear(stacks.b, free);
	free(stacks.a);
	free(stacks.b);
}
