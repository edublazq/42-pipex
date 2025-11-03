/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edblazqu <edblazqu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:15:56 by edblazqu          #+#    #+#             */
/*   Updated: 2025/10/01 11:15:58 by edblazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/* static void	function(unsigned int idx, char *string)
{
	printf("Pasada:%d %s\n", idx, string);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_striteri(av[1], function);
	return (0);
} */
