/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 12:55:10 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/31 15:27:47 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <string.h>

Test(ft_strlcpy, test_segfault_dst, .signal=11)
{
	ft_strlcpy(NULL, "test", 3);
}

Test(ft_strlcpy, test_segfault_src, .signal=11)
{
	char	dst[50];
	ft_strlcpy(dst, NULL, 43);
}

Test(ft_strlcpy, test_src_lt_dst)
{
	char	test[50];
	char	expected[50];

	cr_assert_eq(strlcpy(expected, "bien", 50), ft_strlcpy(test, "bien", 50));
	cr_assert_str_eq(expected, test);
	cr_assert_eq(test[4], 0);
}

Test(ft_strlcpy, test_tronc)
{
	char	test[5];
	char	expected[5];

	cr_assert_eq(strlcpy(expected, "omedeto, shinji", 5), ft_strlcpy(test, "omedeto, shinji", 5));
	cr_assert_str_eq(test, expected);
	cr_assert_eq(test[4], 0);
}

Test(ft_strlcpy, test_dsize_1)
{
	char	test[5];

	cr_assert_eq(4, ft_strlcpy(test, "test", 1));
	cr_assert_eq(test[0], 0);
}

Test(ft_strlcpy, test_empty_src)
{
	char	test[5];

	cr_assert_eq(0, ft_strlcpy(test, "", 5));
	cr_assert_eq(test[0], 0);
}
