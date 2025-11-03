/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamberger12 <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:52:09 by bamberger12       #+#    #+#             */
/*   Updated: 2025/08/12 16:52:10 by bamberger12      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_digits(int n)
{
	int		digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*ascii;
	size_t	sign;
	size_t	digits;

	nb = (long)n;
	digits = num_digits(n);
	sign = 0;
	if (nb < 0)
		sign = 1;
	if (sign)
		nb = -nb;
	ascii = (char *)malloc(digits + sign + 1);
	if (!ascii)
		return (NULL);
	ascii[digits + sign] = '\0';
	while (digits > 0)
	{
		ascii[digits + sign - 1] = nb % 10 + '0';
		nb /= 10;
		digits--;
	}
	if (sign)
		ascii[0] = '-';
	return (ascii);
}

/* int	main(void)
{
	ft_putstr_fd(ft_itoa(-2147483648), 1);
} */
