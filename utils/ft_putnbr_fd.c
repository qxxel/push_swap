/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:20:09 by agerbaud          #+#    #+#             */
/*   Updated: 2024/01/09 14:43:01 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_putnbr_fd(int n, int fd, int *nb_char)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd, nb_char);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd, nb_char);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd, nb_char);
		ft_putnbr_fd(n % 10, fd, nb_char);
	}
	else if (n >= 0 && (*nb_char) >= 0)
		ft_putchar_fd(n + '0', fd, nb_char);
}
