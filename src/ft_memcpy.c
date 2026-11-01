/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 16:24:43 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/24 16:25:02 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*cpy_dest;
	char	*cpy_src;
	size_t	i;

	i = 0;
	cpy_dest = (char *)dest;
	cpy_src = (char *)src;
	while (i < n && i < sizeof(src))
	{
		cpy_dest[i] = cpy_src[i];
		i++;
	}
	return (dest);
}
