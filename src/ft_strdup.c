/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 16:22:33 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/24 16:23:17 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	while (i <= len + 1)
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}
