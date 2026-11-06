/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 17:06:42 by resonnet          #+#    #+#             */
/*   Updated: 2026/11/05 14:15:11 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static int	is_sep(char c, const char *sep)
{
	size_t	i;

	i = 0;
	while (sep[i])
	{
		if (c == sep[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	get_end(const char *s, const char *sep)
{
	int		i;

	i = ft_strlen(s) - 1;
	while (i >= 0 && is_sep(s[i], sep))
		i--;
	return (i);
}

static size_t	get_start(const char *s, const char *sep)
{
	size_t	i;

	i = 0;
	while (s[i] && is_sep(s[i], sep))
		i++;
	return (i);
}

static size_t	get_str_size(const char *s, const char *sep)
{
	size_t	start;
	size_t	end;

	start = get_start(s, sep);
	end = get_end(s, sep);
	if (start == ft_strlen(s) || !end)
		return (ft_strlen(s));
	return (end - start + 1);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	size;

	start = get_start(s1, set);
	size = get_str_size(s1, set);
	return (ft_substr(s1, start, size));
}
/*
#include <stdio.h>
int	main(void)
{
	char	*s = ft_strtrim("ababa", "a");

	printf("%s", s);
}
*/
