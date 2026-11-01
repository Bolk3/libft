/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 17:24:26 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/27 17:34:46 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

static int	get_array_size(const char *s, int c)
{
	int	res;
	int i;

	res = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		res++;
		while (s[i] == c && s[i])
			i++;
	}
	return (res);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	int		tab;
	int		i;
	int		j;

	tab = 0;
	i = 0;
	res = malloc(get_array_size(s, c));
	if (!res)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[j] != c && s[j])
			j++;
		res[tab++] = ft_substr(s, i, j);
		i = j;
	}
	res[tab] = NULL;
	return (res);
}
