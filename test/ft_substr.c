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
#include <string.h>

static void	teardown(void)
{
	should_malloc_fail = false;
}

TestSuite(ft_substr, .fini=teardown);
Test(ft_substr, test_segfault, .signal=11)
{
	ft_substr(NULL, 13, 1);
}

Test(ft_substr, test_start_gt_string_size)
{
	char	*test = ft_substr("omedeto", 42, 4);

	cr_assert_null(test);
}

Test(ft_substr, test_start_plus_len_gt_string_start)
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

Test(ft_substr, test_start_plus_len_lt_string_start)
{
	int		start = 2;
	int		len = 8;
	char	*string = "omdedeto, shinji";
	char	*expected = strndup(string + start, len);
	char	*test = ft_substr(string, start, len);

	cr_assert_not_null(test);
	cr_assert_str_eq(expected, test);
}
