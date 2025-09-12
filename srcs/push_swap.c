/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:28:40 by agerbaud          #+#    #+#             */
/*   Updated: 2025/09/12 11:29:24 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stacks;
	bool	exit_status;

	exit_status = init_stack(argc - 1, argv + 1, &stacks);
	if (exit_status)
		ft_putstr_fd("Error\n", 2);
	else if (!is_sorted_stack(*stacks.a))
		sort_stack(stacks, ft_lstsize(*stacks.a));
	free_stacks(stacks);
	return (exit_status);
}
