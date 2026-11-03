/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 17:06:42 by resonnet          #+#    #+#             */
/*   Updated: 2026/11/03 15:08:19 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static int	is_sep(const char c, const char *sep)
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

static int	get_str_size(const char *s, const char *set)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	start = 0;
	end = 0;
	while (s[i] && is_sep(s[i], set))
	{
		i++;
		start++;
	}
	i = ft_strlen(s) - 1;
	while (i >= 0 && is_sep(s[i], set))
	{
		i--;
		end++;
	}
	if (start && end && start == end)
		return (0);
	return (ft_strlen(s) - (start + end));
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*res;
	size_t	i;
	size_t	j;
	int		ssize;

	i = 0;
	j = 0;
	ssize = get_str_size(s1, set);
	res = malloc(ssize + 1);
	if (!res)
		return (NULL);
	while (s1[i] && is_sep(s1[i], set))
		i++;
	while (s1[i] && !is_sep(s1[i], set))
		res[j++] = s1[i++];
	res[j] = 0;
	return (res);
}

/*
int	main(void)
{
	ft_strtrim("   xxx   xxx", " x");
}
*/
