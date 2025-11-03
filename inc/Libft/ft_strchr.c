/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamberger12 <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 19:37:24 by bamberger12       #+#    #+#             */
/*   Updated: 2025/08/10 19:37:24 by bamberger12      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if ((unsigned char)c == '\0')
		return ((char *)&(s[ft_strlen(s)]));
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

/* int	main(void)
{
	char	*test;

	test = "teste";
	printf("%p\n", test);
	printf("%p", ft_strchr(test, '\0'));
}
 */