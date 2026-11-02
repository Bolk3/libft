/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 18:59:14 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/25 19:03:29 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	strsize;
	size_t	size;

	i = 0;
	strsize = ft_strlen(s);
	if (start > strsize)
		return (ft_strdup(""));
	else if (start + len > strsize)
		size = len - (start + len - strsize);
	else
		size = len;
	res = malloc(size + 1);
	if (!res)
		return (NULL);
	while (s[start + i] && i < size)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = 0;
	return (res);
}
