/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamberger12 <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 19:39:45 by bamberger12       #+#    #+#             */
/*   Updated: 2025/08/10 19:39:46 by bamberger12      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}

/* #include <stdio.h>

int	main(void)
{
	char	f[10];
	int		i;

	i = 0;
	while (i < 10)
	{
		f[i] = 'x';
		i++;
	}
	ft_bzero(f+3, 10);
	i = 0;
	while (i < 10)
	{
		printf("%d\n", f[i]);
		i++;
	}
	return (0);
} */
