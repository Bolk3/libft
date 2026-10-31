/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 11:27:14 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/31 11:45:09 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>

Test(ft_memcmp, test_segfault_s1, .signal=11)
{
	int	test = 0;
	int value = ft_memcmp(NULL, &test, 32);
	(void)value;
}

Test(ft_memcmp, test_segfault_s2, .signal=11)
{
	int	test = 0;
	int	value = ft_memcmp(&test, NULL, 32);
	(void)value;
}

Test(ft_memcmp, test_s1_lt_s2_in_range)
{
	char	*s1 = "abc";
	char	*s2 = "bcd";
	int		test = ft_memcmp(s1, s2, 3);

	cr_assert_lt(test, 0);
}

Test(ft_memcmp, test_s1_gt_s2_in_range)
{
	char	*s1 = "bcd";
	char	*s2 = "abc";
	int		test = ft_memcmp(s1, s2, 3);

	cr_assert_gt(test, 0);
}

Test(ft_memcmp, test_s1_eq_s2_in_range)
{
	char	*s1 = "abc";
	char	*s2 = "abc";
	int		test = ft_memcmp(s1, s2, 3);

	cr_assert_eq(test, 0);
}

Test(ft_memcmp, test_difference_outside_range)
{
	char	*s1 = "abcd";
	char	*s2 = "abcg";
	int		test = ft_memcmp(s1, s2, 3);

	cr_assert_eq(test, 0);
}
