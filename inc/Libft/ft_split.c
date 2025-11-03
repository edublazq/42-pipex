/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamberger12 <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:21:25 by bamberger12       #+#    #+#             */
/*   Updated: 2025/08/14 15:21:26 by bamberger12      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	count_words(const char *s, char c)
{
	size_t	words;
	size_t	i;
	int		inside_word;

	i = 0;
	words = 0;
	inside_word = 0;
	while (s[i])
	{
		if (inside_word == 0 && s[i] != c)
		{
			words++;
			inside_word = 1;
		}
		else if (inside_word == 1 && s[i] == c)
			inside_word = 0;
		i++;
	}
	return (words);
}

static	size_t	word_length(const char *s, char c)
{
	size_t	length;

	length = 0;
	while (s[length] && s[length] != c)
		length++;
	return (length);
}

static	void	*free_all(char **split, size_t	idx)
{
	size_t	i;

	i = 0;
	while (i < idx)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static char	*fill_string(char *s, char *to_fill, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = word_length(s, c);
	while (i < len)
	{
		to_fill[i] = s[i];
		i++;
	}
	to_fill[i] = '\0';
	return (&s[i]);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	char	*ptr;
	size_t	i;
	size_t	limits;

	ptr = (char *)s;
	limits = count_words(s, c);
	i = 0;
	split = (char **)malloc(sizeof(char *) * (limits + 1));
	if (!split)
		return (NULL);
	while (i < limits)
	{
		while (*ptr == c)
			ptr++;
		split[i] = (char *)malloc(word_length(ptr, c) + 1);
		if (!split[i])
			return ((char **)free_all(split, i));
		ptr = fill_string(ptr, split[i], c);
		i++;
	}
	split[i] = NULL;
	return (split);
}

/* int	main(int argc, char **argv)
{
	char	**split;
	int		limit;

	if (argc == 2)
	{
		printf("%d", (int)ft_strlen(argv[1]));
		split = ft_split(argv[1], ' ');
		for (int i = 0; split[i]; i++)
		{
			printf("Split nº %d -> %s\n", i, split[i]);
			limit = i;
		}
		printf("NULL -> %s", split[limit + 1]);
		for (int i = 0; split[i]; i++)
			free(split[i]);
		free(split);
	}
	return (0);
} */
