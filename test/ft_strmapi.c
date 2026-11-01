/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 11:39:47 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/30 12:05:28 by resonnet         ###   ########.fr       */
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

char	manip(unsigned int i, char c)
{
	(void)i;
	return (c);
}

TestSuite(ft_strmapi, .init=setup, .fini=teardown);
Test(ft_strmapi, test_malloc_fail)
{
	malloc_fail_at = 1;
	char	*test = ft_strmapi("test", manip);

	cr_assert_null(test);
}

Test(ft_strmapi, test_segfault, .signal=11)
{
	ft_strmapi(NULL, manip);
}

Test(ft_strmapi, test_empty_str)
{
	char	*test = ft_strmapi("", manip);

	cr_assert_not_null(test);
	cr_assert_str_empty(test);
}

Test(ft_strmapi, test_str)
{
	char	*str = "omedeto, shinji";
	char	*test = ft_strmapi(str, manip);
	
	cr_assert_not_null(test);
	cr_assert_str_not_empty(test);
	cr_assert_str_eq(test, str);
}
