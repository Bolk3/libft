/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 17:06:42 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/27 17:22:50 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stddef.h>
#include <stdlib.h>

static size_t	get_new_size(const char *str, const char *set)
{
	size_t	res;
	size_t	i;

	res = 0;
	i = 0;
	while (str[i])
	{
		if (!ft_strchr(set, str[i]))
			res++;
		i++;
	}
	return (res);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*res;
	size_t	i;
	size_t	tab;

	i = 0;
	tab = 0;
	res = malloc(get_new_size(s1, set));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		if (ft_strchr(set, s1[i]))
			res[tab++] = s1[i];
		i++;
	}
	res[tab] = 0;
	return (res);
}
