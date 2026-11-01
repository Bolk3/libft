/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 16:26:34 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/24 16:53:23 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest_cpy;
	const char	*src_cpy;
	size_t		i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	dest_cpy = (char *)dest;
	src_cpy = (const char *)src;
	if (dest_cpy > src_cpy)
	{
		while (n-- > 0)
			dest_cpy[n] = src_cpy[n];
	}
	else
	{
		while (i++ < n)
			dest_cpy[i] = src_cpy[i];
	}
	return (dest);
}
