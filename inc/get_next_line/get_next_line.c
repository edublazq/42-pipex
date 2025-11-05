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

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*join;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	join = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
		return (NULL);
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		join[i + j] = s2[j];
		j++;
	}
	join[i + j] = '\0';
	free(s1);
	free(s2);
	return (join);
}

char	*new_hold(char *hold, int fd, int *read_info)
{
	char	*buffer;

	if (!hold)
		hold = ft_strdup("");
	while (1)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		*read_info = read(fd, buffer, BUFFER_SIZE);
		if (*read_info == -1)
		{
			free(buffer);
			free(hold);
			return (NULL);
		}
		buffer[*read_info] = '\0';
		hold = ft_strjoin_gnl(hold, buffer);
		if (ft_strchr(hold, '\n'))
			break ;
		if (*read_info == 0)
			break ;
	}
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
	{
		output = ft_strdup(*hold);
		free(*hold);
		*hold = NULL;
		return (output);
	}
	i = end - *hold + 1;
	output = ft_substr(*hold, 0, i);
	tmp = ft_strdup(end + 1);
	free(*hold);
	*hold = tmp;
	return (output);
}

char	*get_next_line(int fd)
{
	char		*output;
	static char	*hold;
	int			read_info;

	read_info = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (hold)
			free(hold);
		return (NULL);
	}
	hold = new_hold(hold, fd, &read_info);
	if (read_info == 0 && (!hold || *hold == '\0'))
	{
		if (hold)
			free(hold);
		hold = NULL;
		return (NULL);
	}
	output = search_hold(&hold);
	if (read_info == 0 && (!hold || *hold == '\0'))
		free(hold);
	return (output);
}
