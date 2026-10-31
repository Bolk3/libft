/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 09:34:54 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/30 10:03:21 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "wraps.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>

static void	teardown(void)
{
	should_malloc_fail = false;
}

TestSuite(ft_strtrim, .fini=teardown);
Test(ft_strtrim, test_malloc_fail)
{
	should_malloc_fail = true;
	char	*test = ft_strtrim("omedeto, shinji", ",");

	cr_assert_null(test);
}

Test(ft_strtrim, test_empty_str_return_empty_str)
{
	char	*test = ft_strtrim("", " ");

	cr_assert_not_null(test);
	cr_assert_str_empty(test);
}

Test(ft_strtrim, test_empty_charset_return_full_str)
{
	char	*str = "omedeto, shinji";
	char	*test = ft_strtrim(str, "");

	cr_assert_not_null(test);
	cr_assert_str_not_empty(test);
	cr_assert_str_eq(test, str);
}

Test(ft_strtrim, test_null_str_segfault, .signal=11)
{
	ft_strtrim(NULL, "");
}

Test(ft_strtrim, test_null_charset_segfault, .signal=11)
{
	ft_strtrim("omedeto, shinji", NULL);
}

Test(ft_strtrim, test_charset_not_present_in_str)
{
	char	*str = "omedeto, shinji";
	char	*test = ft_strtrim(str, "a");

	cr_assert_not_null(test);
	cr_assert_str_not_empty(test);
	cr_assert_str_eq(test, str);
}

Test(ft_strtrim, test_charset_in_str)
{
	char	*str = "omedeto, shinji";
	char	*expected = "omedeto,shinji";
	char	*test = ft_strtrim(str, " ");

	cr_assert_not_null(test);
	cr_assert_str_not_empty(test);
	cr_assert_str_eq(test, expected);
}
