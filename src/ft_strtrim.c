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

static int	is_sep(const char c, const char *set)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (set[i])
	{
		if (c == set[i])
		{
			flag = 1;
			break ;
		}
		i++;
	}
	return (flag);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = malloc(get_new_size(s1, set) + 1);
	if (!res)
		return (res);
	while (s1[i])
	{
		if (!is_sep(s1[i], set))
			res[j++] = s1[i];
		i++;
	}
	res[j] = 0;
	return (res);
}
