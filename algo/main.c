/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:56:18 by agerbaud          #+#    #+#             */
/*   Updated: 2024/01/08 14:00:52 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc <= 1)
		return (ft_printf("%s", "Error\n"), 0);
	stack = put_into_stack(argv);
	if (stack == NULL)
		return (ft_printf("%s", "Error\n"), 0);
	ft_algo(stack);
	return (0);
}
