/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 21:36:24 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/24 21:42:14 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/internal/test.h>
#include <libft.h>
#include <criterion/assert.h>
#include <ctype.h>
#include <limits.h>

Test(ft_isalnum, test_all_char_range)
{
	for (int i = CHAR_MIN; i <= CHAR_MAX; i++) {
		cr_assert_eq(ft_isalnum(i) != 0, isalnum(i) != 0);
	}
}
