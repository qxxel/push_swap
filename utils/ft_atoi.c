/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:21:42 by agerbaud          #+#    #+#             */
/*   Updated: 2024/01/08 13:02:29 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// static int	ft_is_white_space(char c)
// {
// 	if (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
// 		|| c == '\v')
// 		return (1);
// 	else
// 		return (0);
// }

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	nb;

	i = 0;
	nb = 0;
	sign = 1;
	if (nptr[i] == '-')
	{
		sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (nb != (nb * 10 + (nptr[i] - '0')) / 10)
			return (-(sign > 0));
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	if (nptr[i] != 0)
		return (-1);
	return (sign * nb);
}
