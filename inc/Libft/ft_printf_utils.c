/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamberger12 <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:45:18 by bamberger12       #+#    #+#             */
/*   Updated: 2025/08/27 14:45:18 by bamberger12      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *str)
{
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_print_unsigned(unsigned int nb)
{
	int	digits;

	digits = 0;
	ft_putunbr_fd(nb, 1);
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 10;
		digits++;
	}
	return (digits);
}

void	ft_print_to_base(unsigned int nb, char *base, int *i)
{
	size_t	len;

	len = ft_strlen(base);
	if (nb < len)
	{
		ft_putchar_fd(base[nb], 1);
		(*i)++;
	}
	else
	{
		ft_print_to_base(nb / len, base, i);
		ft_print_to_base(nb % len, base, i);
	}
}

static void	ft_print_ptr_base(uintptr_t nb, char *base, int *i)
{
	size_t	len;

	len = ft_strlen(base);
	if (nb < len)
	{
		ft_putchar_fd(base[nb], 1);
		(*i)++;
	}
	else
	{
		ft_print_ptr_base(nb / len, base, i);
		ft_print_ptr_base(nb % len, base, i);
	}
}

int	ft_print_ptr(void *ptr)
{
	uintptr_t	address;
	int			i;

	i = 0;
	if (ptr == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	address = (uintptr_t)ptr;
	ft_putstr_fd("0x", 1);
	i = 2;
	ft_print_ptr_base(address, "0123456789abcdef", &i);
	return (i);
}
