/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wraps.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 12:18:45 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/29 12:28:23 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define	WRAPS_H
#ifdef WRAPS_H
# include <stddef.h>

extern int	malloc_fail_at;

extern void	*__real_malloc(size_t size);
void		*__wrap_malloc(size_t size);
#endif // WRAPS_H
