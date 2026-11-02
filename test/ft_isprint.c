/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 22:00:44 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/24 22:08:38 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/internal/test.h>
#include <libft.h>
#include <criterion/assert.h>
#include <criterion/internal/assert.h>
#include <ctype.h>
#include <limits.h>

Test(ft_isprint, test_all_char_range)
{
	for (int i = CHAR_MIN; i <= CHAR_MAX; i++) {
		cr_assert_eq(ft_isprint(i) != 0, isprint(i) != 0);
	}
}
