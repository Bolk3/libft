/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 17:08:02 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/24 17:14:34 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	i;
	size_t	j;
	size_t	og_dest;

	i = 0;
	j = 0;
	og_dest = ft_strlen(dst);
	while (dst[i])
		i++;
	while (src[j] && i + j < dsize - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[j + i] = 0;
	return (og_dest + ft_strlen(src));
}
