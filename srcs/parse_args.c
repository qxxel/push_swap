/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:11:06 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/03 11:55:52 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static bool	atoi_safe(char *s, int *n)
{
	unsigned int	u;

	if (!s)
		return (true);
	*n = 1;
	u = 0;
	if (*s == '-' || *s == '+')
		*n -= 2 * (*s++ == '-');
	if (!ft_isdigit(*s))
		return (true);
	while (ft_isdigit(*s))
	{
		u = u * 10 + *s++ - '0';
		if (u > INT_MAX && (*n != -1 || u != (unsigned int)INT_MAX + 1))
			return (true);
	}
	*n *= u;
	return (*s != 0);
}

static bool	is_duplicate(int value, t_list *stack)
{
	while (stack)
	{
		if (((t_value *)stack->content)->value == value)
			return (true);
		stack = stack->next;
	}
	return (false);
}

static bool	new_elem(char *arg, t_list **stack)
{
	int		value;
	t_value	*elem;
	t_list	*new;

	if (atoi_safe(arg, &value) || is_duplicate(value, *stack))
		return (true);
	elem = malloc(sizeof(t_value));
	if (!elem)
		return (true);
	elem->value = value;
	new = ft_lstnew(elem);
	if (!new)
		return (true);
	ft_lstadd_back(stack, new);
	return (false);
}

void	free_tab(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map[i]);
	free(map);
}

bool	parse_args(int argc, char **argv, t_list **stack)
{
	char	**args;
	int	i;
	bool	error;

	if (!argc)
		return (false);
	args = ft_split(*argv, ' ');
	if (!args)
		return (true);
	i = 0;
	error = 0;
	while (args[i] && !error)
		error = new_elem(args[i++], stack);
	free_tab(args);
	if (error)
		return (true);
	return (parse_args(argc - 1, argv + 1, stack));
}
