/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamberger12 <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:32:05 by bamberger12       #+#    #+#             */
/*   Updated: 2025/08/25 23:32:06 by bamberger12      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list vargs, char c)
{
	int		i;

	i = 0;
	if (c == 'c')
		ft_putchar_fd(va_arg(vargs, int), 1);
	else if (c == 's')
		return (ft_print_string(va_arg(vargs, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_print_number(va_arg(vargs, int)));
	else if (c == 'u')
		return (ft_print_unsigned(va_arg(vargs, unsigned int)));
	else if (c == 'x')
		ft_print_to_base(va_arg(vargs, unsigned int), "0123456789abcdef", &i);
	else if (c == 'X')
		ft_print_to_base(va_arg(vargs, unsigned int), "0123456789ABCDEF", &i);
	else if (c == '%')
		ft_putchar_fd('%', 1);
	else if (c == 'p')
		return (ft_print_ptr(va_arg(vargs, void *)));
	else
		return (-1);
	if (c == 'x' || c == 'X')
		return (i);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list		vargs;
	int			i;
	int			count;

	va_start(vargs, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_format(vargs, str[i + 1]);
			if (count == -1)
				return (-1);
			i += 2;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			i++;
			count++;
		}
	}
	va_end(vargs);
	return (count);
}
