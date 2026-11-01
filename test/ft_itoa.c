/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 14:46:42 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/29 15:14:28 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "wraps.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <criterion/logging.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

static void	setup(void)
{
	malloc_fail_at = 0;
}

static void	teardown(void)
{
	malloc_fail_at = 0;
}

TestSuite(ft_itoa, .init=setup, .fini=teardown);

Test(ft_itoa, test_int_min)
{
	int		nbr = INT32_MIN;
	char	*test = ft_itoa(nbr);
	char	expected[500];

	sprintf(expected, "%i", nbr);
	cr_assert_str_eq(expected, test);
}

Test(ft_itoa, test_zero)
{
	int		nbr = 0;
	char	*test = ft_itoa(nbr);
	char	expected[500];

	sprintf(expected, "%i", nbr);
	cr_assert_str_eq(expected, test);
}

Test(ft_itoa, test_rand_int)
{
	srand(time(NULL));
	int		nbr = (rand() % INT32_MAX) + 1;
	char	*test = ft_itoa(nbr);
	char	expected[500];

	sprintf(expected, "%i", nbr);
	cr_assert_str_eq(expected, test);
}

Test(ft_itoa, test_rand_neg_int)
{
	srand(time(NULL));
	int		nbr = ((rand() % INT32_MAX) + 1) * -1;
	char	*test = ft_itoa(nbr);
	char	expected[500];

	sprintf(expected, "%i", nbr);
	cr_assert_str_eq(expected, test);
}

Test(ft_itoa, test_malloc_fail)
{
	malloc_fail_at = 1;
	int		nbr = 42;
	char	*test = ft_itoa(nbr);

	cr_assert_null(test);
}
