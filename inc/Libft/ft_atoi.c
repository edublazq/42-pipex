/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamberger12 <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 19:36:28 by bamberger12       #+#    #+#             */
/*   Updated: 2025/08/10 19:36:29 by bamberger12      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	num;
	int	neg;

	i = 0;
	neg = 1;
	num = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -neg;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = (num * 10) + (nptr[i] - '0');
		i++;
	}
	return (num * neg);
}

/* int main(int argc, char **argv)
{
	ft_putnbr_fd(ft_atoi("-2147483648"), 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(ft_atoi("2147483647"), 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(ft_atoi("0"), 1);
	ft_putchar_fd('\n', 1);
	if (argc == 2)
		ft_putnbr_fd(ft_atoi(argv[1]), 1);
	return (0);
} */
