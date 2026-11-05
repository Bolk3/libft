/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 19:41:18 by resonnet          #+#    #+#             */
/*   Updated: 2026/11/05 20:07:18 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKS_HPP
# define CHECKS_HPP
# include <cstddef>
# include <set>

extern std::set<void *>	mem_alloc;
extern size_t			malloc_fail_at;

extern "C" {
	void	*__real_malloc(size_t size);
	void	__real_free(void *ptr);

	void		*__wrap_malloc(std::size_t size);
	void		__wrap_free(void *ptr);
}
bool		leakCheck(void);

#endif // !CHECKS_HPP
