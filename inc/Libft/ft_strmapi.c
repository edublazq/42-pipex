/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamberger12 <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 17:04:30 by bamberger12       #+#    #+#             */
/*   Updated: 2025/08/22 17:04:31 by bamberger12      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*map_s;

	if (!s || !(*f))
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	map_s = (char *)malloc(len + 1);
	if (!map_s)
		return (NULL);
	while (i < len)
	{
		map_s[i] = f(i, s[i]);
		i++;
	}
	map_s[i] = '\0';
	return (map_s);
}
