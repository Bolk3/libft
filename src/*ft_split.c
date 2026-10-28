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

#include "../include/libft.h"
#include <stddef.h>
#include <stdlib.h>

static int	get_new_size(const char *s, int c)
{
	int	res;
	int	i;
	int	j;

	res = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[j] != c && s[j])
			j++;
	}
	return (res);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	size_t	tab;
	size_t	i;
	size_t	j;
	
	i = 0;
	tab = 0;
	res = malloc(get_new_size(s, c));
	if (!res)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[j] != c && s[j])
			j++;
		res[tab++] = ft_substr(s, i, j - i);
		i = j;
	}
	res[tab] = NULL;
	return (res);
}
