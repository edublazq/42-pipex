/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamberger12 <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 22:37:43 by bamberger12       #+#    #+#             */
/*   Updated: 2025/10/09 22:37:44 by bamberger12      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_hold(char *hold, int fd, int *read_info)
{
	char	*buffer;

	if (!hold)
		hold = ft_strdup("");
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(hold), NULL);
	while (!ft_strchr(hold, '\n') && *read_info != 0)
	{
		*read_info = read(fd, buffer, BUFFER_SIZE);
		if (*read_info == -1)
			return (free(buffer), free(hold), NULL);
		buffer[*read_info] = '\0';
		hold = ft_strjoin(hold, buffer);
		if (!hold)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (hold);
}

char	*search_hold(char **hold)
{
	char	*end;
	char	*tmp;
	char	*output;
	size_t	i;

	if (!*hold || **hold == '\0')
		return (NULL);
	end = ft_strchr(*hold, '\n');
	if (!end)
		return (output = *hold, *hold = NULL, output);
	i = end - *hold + 1;
	output = ft_substr(*hold, 0, i);
	if (!output)
		return (free(*hold), *hold = NULL, NULL);
	tmp = NULL;
	if (*end != '\0')
	{
		tmp = ft_strdup(end + 1);
		if (!tmp)
			return (free(*hold), *hold = NULL, free(output), NULL);
	}
	free(*hold);
	*hold = tmp;
	return (output);
}

char	*get_next_line(int fd)
{
	char		*output;
	static char	*hold;
	int			read_info;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(hold);
		hold = NULL;
		return (NULL);
	}
	read_info = 1;
	hold = new_hold(hold, fd, &read_info);
	if (read_info == 0 && (!hold || *hold == '\0'))
	{
		free(hold);
		hold = NULL;
		return (NULL);
	}
	output = search_hold(&hold);
	if (hold && *hold == '\0')
	{
		free(hold);
		hold = NULL;
	}
	return (output);
}
