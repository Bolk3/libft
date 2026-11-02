/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 18:19:58 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/25 18:23:44 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*c_s1;
	const char	*c_s2;

	if (!n)
		return (0);
	i = 0;
	c_s1 = (const char *)s1;
	c_s2 = (const char *)s2;
	while (i < n - 1)
	{
		if (c_s1[i] == c_s2[i])
			i++;
		else
			break ;
	}
	return (c_s2[i] - c_s1[i]);
}
