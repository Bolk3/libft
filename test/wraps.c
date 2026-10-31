/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wraps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 12:13:16 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/29 15:14:36 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wraps.h"

int	malloc_fail_at = 0;

void	*__wrap_malloc(size_t size)
{
	if (malloc_fail_at > 0 && --malloc_fail_at == 0)
		return (NULL);
	return (__real_malloc(size));
}
