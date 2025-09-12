/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:55:04 by agerbaud          #+#    #+#             */
/*   Updated: 2025/09/12 11:29:24 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	init_stack(int argc, char **argv, t_stack *stacks)
{
	stacks->a = malloc(sizeof(t_list *));
	stacks->b = malloc(sizeof(t_list *));
	if (!stacks->a || !stacks->b)
		return (true);
	*stacks->a = NULL;
	*stacks->b = NULL;
	return (parse_args(argc, argv, stacks->a));
}
