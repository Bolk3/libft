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

#include "../include/libft.h"
#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*s1_c;
	const char	*s2_c;

	i = 0;
	s1_c = (const char *)s1;
	s2_c = (const char *)s2;
	while (i < n - 1 && s1_c[i] == s2_c[i])
		i++;
	return (s1_c[i] - s2_c[i]);
}
