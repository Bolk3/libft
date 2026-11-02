/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 18:55:21 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/25 18:58:00 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <strings.h>
#include <sys/mman.h>

void	*ft_calloc(size_t n, size_t size)
{
	char	*res;
	size_t	msize;

	if (!n || !size)
		msize = 1;
	else if (n > MAP_32BIT|| size > MAP_32BIT)
		return (NULL);
	else
		msize = n * size;
	res = malloc(msize);
	if (!res)
		return (NULL);
	bzero(res, msize);
	return (res);
}
