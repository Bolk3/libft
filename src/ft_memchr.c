/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 17:53:16 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/25 18:19:13 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*cpy;
	size_t	i;

	i = 0;
	cpy = (char *)s;
	while (i < n)
	{
		if (cpy[i] == c)
			return (cpy + i);
		i++;
	}
	return (NULL);
}
