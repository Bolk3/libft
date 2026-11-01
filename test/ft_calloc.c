/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 13:46:03 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/30 13:52:55 by resonnet         ###   ########.fr       */
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

TestSuite(ft_calloc, .init=setup, .fini=teardown);
Test(ft_calloc, test_malloc_fail)
{
	malloc_fail_at = 1;
	char	*test = ft_calloc(10, 1);

	cr_assert_null(test);
}

Test(ft_calloc, test_type_size_zero_should_return_null)
{
	char	*test = ft_calloc(10, 0);

	cr_assert_null(test);
}

Test(ft_calloc, test_size_zero_should_return_null)
{
	char	*test = ft_calloc(0, 1);

	cr_assert_null(test);
}

Test(ft_calloc, test_all_bytes_are_zero)
{
	char	*test = ft_calloc(10, 1);

	for (int i = 0; i < 10; i++)
	{
		cr_assert_eq(test[i], 0);
	}
}
