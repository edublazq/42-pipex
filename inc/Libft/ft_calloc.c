/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamberger12 <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 19:36:44 by bamberger12       #+#    #+#             */
/*   Updated: 2025/08/10 19:36:45 by bamberger12      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	if (size != 0 && nmemb >= __INT_MAX__ / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	while (i < nmemb * size)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

/* #include <stdio.h>

int	main(void)
{
	char	*hola;

	hola = ft_calloc(5, sizeof(char));
	hola[0] = 'h';
	hola[1] = 'h';
	hola[2] = 'h';
	hola[3] = 'h';
	
	printf("%s\n", hola);
	free(hola);
	return (0);
} */
