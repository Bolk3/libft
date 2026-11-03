/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 17:24:26 by resonnet          #+#    #+#             */
/*   Updated: 2026/11/03 18:10:47 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static char	**cleanup(char **tab, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static size_t	get_array_size(const char *s, char c)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			res++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (res);
}

static char	*get_word(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (ft_substr(s, 0, i));
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	size_t	i;
	size_t	tab;

	i = 0;
	tab = 0;
	res = malloc((get_array_size(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			res[tab] = get_word(s + i, c);
			if (!res[tab++])
				return (cleanup(res, tab));
			while (s[i] && s[i] != c)
				i++;
		}
	}
	res[tab] = NULL;
	return (res);
}
