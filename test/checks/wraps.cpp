/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wraps.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 19:53:05 by resonnet          #+#    #+#             */
/*   Updated: 2026/11/05 20:07:49 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checks.hpp>
#include <cstddef>
#include <set>

std::size_t			malloc_fail_at = 0;
std::set<void *>	mem_alloc;

void	*__wrap_malloc(size_t size)
{
	void	*mem_zone;

	if (malloc_fail_at > 0 && --malloc_fail_at == 0)
		return (NULL);
	else
	{
		mem_zone = __real_malloc(size);
		mem_alloc.insert(mem_zone);
		return (mem_zone);
	}
}

void	__wrap_free(void *ptr)
{
	mem_alloc.erase(ptr);
	__real_free(ptr);
}
