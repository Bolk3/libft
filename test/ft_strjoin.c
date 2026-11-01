/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 09:07:46 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/30 09:08:29 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "wraps.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <stdio.h>

static void	setup(void)
{
	malloc_fail_at = 0;
}

static void	teardown(void)
{
	malloc_fail_at = 0;
}

TestSuite(ft_strjoin, .init=setup, .fini=teardown);
Test(ft_strjoin, test_malloc_fail)
{
	malloc_fail_at = 1;
	char	*s1 = "omedeto";
	char	*s2 = ", shinji";
	char	*test = ft_strjoin(s1, s2);

	cr_assert_null(test);
}

Test(ft_strjoin, test_segfault_s1, .signal=11)
{
	ft_strjoin(NULL, ", shinji");
}

Test(ft_strjoin, test_segfault_s2, .signal=11)
{
	ft_strjoin("omedeto", NULL);
}

Test(ft_strjoin, test_empty_s1_should_return_s2)
{
	char	*s2 = ", shinji";
	char	*test = ft_strjoin("", s2);

	cr_assert_not_null(test);
	cr_assert_str_eq(s2, test);
}

Test(ft_strjoin, test_empty_s2_should_return_s1)
{
	char	*s1 = "omedeto";
	char	*test = ft_strjoin(s1, "");

	cr_assert_not_null(test);
	cr_assert_str_eq(s1, test);
}

Test(ft_strjoin, test_should_return_s1_plus_s2)
{
	char	*s1 = "omedeto";
	char	*s2 = ", shinji";
	char	expected[500];
	char	*test = ft_strjoin(s1, s2);

	sprintf(expected, "%s%s", s1, s2);
	cr_assert_not_null(test);
	cr_assert_str_eq(test, expected);
}
