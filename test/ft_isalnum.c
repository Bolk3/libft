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

#include "../include/libft.h"
#include <criterion/assert.h>
#include <ctype.h>
#include <limits.h>
#include <criterion/criterion.h>

Test(ft_isalnum, test_all_lowercase)
{
	for (int i = 'a'; i <= 'z'; i++) {
		cr_assert_eq(ft_isalnum(i) != 0, isalnum(i) != 0);
	}
}

Test(ft_isalnum, test_all_uppercase)
{
	for (int i = 'A'; i <= 'Z'; i++) {
		cr_assert_eq(ft_isalnum(i) != 0, isalnum(i) != 0);
	}
}

Test(ft_isalnum, test_all_digit)
{
	for (int i = '0'; i <= '9'; i++) {
		cr_assert_eq(ft_isalnum(i) != 0, isalnum(i) != 0);
	}
}

Test(ft_isalnum, test_all_non_alnum)
{
	for (int i = CHAR_MIN; i <= CHAR_MAX; i++) {
		if (!isalnum(i))
			cr_assert_eq(ft_isalnum(i) != 0, isalnum(i) != 0);
	}
}
