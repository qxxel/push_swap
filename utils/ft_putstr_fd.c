/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:11:33 by agerbaud          #+#    #+#             */
/*   Updated: 2024/01/09 14:43:15 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_putstr_fd(char *s, int fd, int *nb_char)
{
	size_t	i;

	if (!s)
	{
		ft_putstr_fd("(null)", 1, nb_char);
		return ;
	}
	i = 0;
	while (s[i] && (*nb_char) >= 0)
	{
		ft_putchar_fd(s[i], fd, nb_char);
		i++;
	}
}
