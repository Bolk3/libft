/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 16:24:59 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/29 16:27:52 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "wraps.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>

static void	teardown(void)
{
	malloc_fail_at = 0;
}

static void	setup(void)
{
	malloc_fail_at = 0;
}

TestSuite(ft_substr, .init=setup, .fini=teardown);
Test(ft_substr, test_malloc_fail)
{
	malloc_fail_at = 1;
	char	*str = "tien tien tien";
	char	*test = ft_substr(str, 1, 4);

	cr_assert_null(test);
}

Test(ft_substr, test_segfault, .signal=11)
{
	ft_substr(NULL, 13, 1);
}

Test(ft_substr, test_start_gt_string_size)
{
	char	*test = ft_substr("omedeto", 42, 4);

	cr_assert_null(test);
}

Test(ft_substr, test_start_plus_len_gt_string_size)
{
	int		start = 2;
	int		len = 30;
	char	*string = "omdedeto, shinji";
	char	*expected = "dedeto, shinji";
	char	*test = ft_substr(string, start, len);

	cr_assert_not_null(test);
	cr_assert_str_not_empty(test);
	cr_assert_str_eq(test, expected);
}

Test(ft_substr, test_start_plus_len_lt_string_size)
{
	int		start = 2;
	int		len = 8;
	char	*string = "omdedeto, shinji";
	char	*test = ft_substr(string, start, len);

	cr_assert_not_null(test);
}
