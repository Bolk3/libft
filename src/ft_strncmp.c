/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 17:48:05 by resonnet          #+#    #+#             */
/*   Updated: 2026/11/03 18:07:20 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*c_s1;
	const unsigned char	*c_s2;

	i = 0;
	c_s1 = (const unsigned char *)s1;
	c_s2 = (const unsigned char *)s2;
	if (!n || (!ft_strlen(s1) && !ft_strlen(s2)))
		return (0);
	else
	{
		while (i < n - 1 && c_s1[i] && c_s2[i] && c_s1[i] == c_s2[i])
			i++;

	}
	return (c_s1[i] - c_s2[i]);
}
