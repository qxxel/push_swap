/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_into_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:56:21 by agerbaud          #+#    #+#             */
/*   Updated: 2024/01/12 10:10:39 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static int	check_error(char *element)
{
	int	i;

	i = 1;
	if (element[0] != '-')
		return (1);
	while (element[i])
	{
		if (element[i] == '0')
			i++;
		else if (element[i] == '1')
		{
			if (element[i + 1] == '\0')
				return (0);
			else
				return (1);
		}
		else
			return (1);
	}
	if (element[i - 1] != '1')
		return (1);
	return (0);
}

t_stack	*put_into_stack(char **list)
{
	t_stack	*stack;
	int		i;

	i = 2;
	stack = ft_lstnew(ft_atoi(list[1]));
	if (stack->nbr == -1 && check_error(list[1]) == 1)
		return (NULL);
	while (list[i] && i >= 2)
	{
		ft_lstadd_front(&stack, ft_lstnew(ft_atoi(list[i])));
		if (stack->nbr == -1 && check_error(list[i]) == 1)
			return (NULL);
		i++;
	}
	return (stack);
}
