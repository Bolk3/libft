/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 16:21:36 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/24 16:22:18 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stddef.h>

void	*ft_memset(void *a, int c, size_t n)
{
	size_t	i;
	char	*cpy;

	i = 0;
	cpy = (char *)a;
	while (i++ < n)
		cpy[i] = c;
	return (a);
}
