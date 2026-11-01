/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 13:32:54 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/30 13:44:45 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "wraps.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>

static void	setup(void)
{
	malloc_fail_at = 0;
}

static void	teardown(void)
{
	malloc_fail_at = 0;
}

TestSuite(ft_strdup, .init=setup, .fini=teardown);

Test(ft_strdup, test_malloc_fail)
{
	malloc_fail_at = 1;
	char	*str = "test";
	char	*test = ft_strdup(str);

	cr_assert_null(test);
}

Test(ft_strdup, test_segfault, .signal=11)
{
	ft_strdup(NULL);
}

Test(ft_strdup, test_empty)
{
	char	*str = "";
	char	*test = ft_strdup(str);

	cr_assert_not_null(test);
	cr_assert_str_empty(test);
}

Test(ft_strdup, test_str)
{
	char	*str = "omedeto, shinji";
	char	*test = ft_strdup(str);

	cr_assert_not_null(test);
	cr_assert_str_not_empty(test);
	cr_assert_str_eq(test, str);
}
