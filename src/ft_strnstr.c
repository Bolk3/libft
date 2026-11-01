/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 18:27:53 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/25 18:34:44 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (big[i] && i < len)
	{
		if (!little[j])
			return ((char *)big + i);
		if (big[i + j] == little[j])
			j++;
		else if (big[i + j] != little[j] && !j)
			i++;
		else
		{
			i += j;
			j = 0;
		}
	}
	return (NULL);
}
