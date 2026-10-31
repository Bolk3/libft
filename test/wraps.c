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
#include <stdbool.h>

bool	should_malloc_fail = false;

void	*__wrap_malloc(size_t size)
{
	if (should_malloc_fail)
		return (NULL);
	return (__real_malloc(size));
}
