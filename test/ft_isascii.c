/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 21:46:57 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/24 21:58:26 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <criterion/criterion.h>
#include <criterion/internal/test.h>
#include <criterion/assert.h>
#include <criterion/internal/assert.h>
#include <limits.h>
#include <ctype.h>

Test(ft_isascii, test_all_char_range)
{
	for (int i = CHAR_MIN; i <= CHAR_MAX; i++) {
		cr_assert_eq(ft_isascii(i) != 0, isascii(i) != 0);
	}
}
