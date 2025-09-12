/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:41:19 by agerbaud          #+#    #+#             */
/*   Updated: 2025/09/12 11:31:37 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	put_error(t_stack stacks)
{
	ft_putstr_fd("Error\n", 2);
	free_stacks(stacks);
	return (1);
}

static bool	switch_operation(char *instruction, t_stack stacks)
{
	const char			*instructions[] = {"sa\n", "sb\n", "ss\n", "pa\n",
		"pb\n", "ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n", NULL};
	const t_operation	operations[] = {swap_a, swap_b, swap_stacks, push_a,
		push_b, rotate_a, rotate_b, rotate_stacks, reverse_rotate_a,
		reverse_rotate_b, reverse_rotate_stacks};
	int					i;

	i = 0;
	while (instructions[i])
	{
		if (!ft_strcmp(instruction, instructions[i]))
		{
			operations[i](stacks);
			return (false);
		}
		i++;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_stack	stacks;
	char	*instruction;

	if (init_stack(argc - 1, argv + 1, &stacks))
		return (put_error(stacks));
	instruction = get_next_line(0);
	while (instruction)
	{
		if (switch_operation(instruction, stacks))
			return (put_error(stacks));
		free(instruction);
		instruction = get_next_line(0);
	}
	if (is_sorted_stack(*stacks.a) && !*stacks.b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stacks(stacks);
	return (0);
}
