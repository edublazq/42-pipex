/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamberger12 <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:58:32 by bamberger12       #+#    #+#             */
/*   Updated: 2025/10/09 11:58:32 by bamberger12      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_number(int nb)
{
	int	digits;

	digits = 0;
	ft_putnbr_fd(nb, 1);
	if (nb < 0)
		digits++;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 10;
		digits++;
	}
	return (digits);
}

void	ft_putunbr_fd(unsigned int nbr, int fd)
{
	if (nbr < 10)
		ft_putchar_fd(nbr + '0', fd);
	else
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putnbr_fd(nbr % 10, fd);
	}
}
