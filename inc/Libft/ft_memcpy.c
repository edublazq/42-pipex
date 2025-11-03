/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamberger12 <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:11:53 by bamberger12       #+#    #+#             */
/*   Updated: 2025/08/14 15:11:54 by bamberger12      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	if (dest > src + n && dest + n > src)
		return (ft_memmove(dest, src, n));
	else
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
		return (dest);
	}
	return (NULL);
}

/* int	main(void)
{
	char	*src;
	char	*dest;

	src = "hola mundo";
	dest = malloc(ft_strlen(src) + 1);
	if (!dest)
		return (-1);
	ft_memcpy(dest, src, ft_strlen(src));
	printf("%s", dest);
	free(dest);
	return (0);
} */
