/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 10:52:52 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/30 11:38:43 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "wraps.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <stdbool.h>

static void	setup(void)
{
	malloc_fail_at = 0;
}

static void	teardown(void)
{
	malloc_fail_at = 0;
}

static int	lstsize(char **lst)
{
	int	i;

	i = 0;
	while (lst[i])
		i++;
	return (i);
}

TestSuite(ft_split, .init=setup, .fini=teardown);
Test(ft_split, test_malloc_fail)
{
	malloc_fail_at = 1;
	char	**test = ft_split("omedeto, shinji", ' ');

	cr_assert_null(test);
}

Test(ft_split, test_segfault, .signal=11)
{
	ft_split(NULL, 'a');
}

Test(ft_split, test_sep_not_in_str)
{
	char	*str = "omedeto, shinji";
	char	**test = ft_split(str, 'z');

	cr_assert_not_null(test);
	cr_assert_eq(lstsize(test), 1);
	cr_assert_str_not_empty(test[0]);
	cr_assert_str_eq(test[0], str);
}

Test(ft_split, test_sep_in_str)
{
	char	*str = "omedeto, shinji";
	char	*expected[] = {"omedeto,", "shinji", NULL};
	char	**test = ft_split(str, ' ');

	cr_assert_not_null(test);
	//cr_assert_eq(lstsize(test), lstsize(expected));
	for (int i = 0; test[i]; i++) {
		cr_assert_not_null(test[i]);
		cr_assert_str_not_empty(test[i]);
		cr_assert_str_eq(test[i], expected[i]);
	}
}
