/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:52:14 by agerbaud          #+#    #+#             */
/*   Updated: 2024/01/09 14:43:09 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_putnbr_unsigned_fd(unsigned int n, int fd, int *nb_char)
{
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd, nb_char);
		ft_putnbr_fd(n % 10, fd, nb_char);
	}
	else if ((*nb_char) >= 0)
		ft_putchar_fd(n + '0', fd, nb_char);
}
