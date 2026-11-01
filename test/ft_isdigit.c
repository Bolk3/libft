/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 21:26:52 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/24 21:31:13 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <ctype.h>
#include <limits.h>

Test(ft_isdigit, test_all_digits)
{
	for (int i = '0'; i <= '9'; i++) {
		cr_assert_eq(ft_isdigit(i) != 0, isdigit(i) != 0);
	}
}

Test(ft_isdigit, test_all_non_digit)
{
	for (int i = CHAR_MIN; i <= CHAR_MAX; i++) {
		if (i < '0' || i > '9')
			cr_assert_eq(ft_isdigit(i) != 0, isdigit(i) != 0);
	}
}
