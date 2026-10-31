/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 12:07:07 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/31 12:18:02 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>

Test(ft_strncmp, test_segfault_s1, .signal=11)
{
	ft_strncmp(NULL, "test", 3);
}

Test(ft_strncmp, test_segfault_s2, .signal=11)
{
	ft_strncmp("test", NULL, 3);
}

Test(ft_strncmp, test_s1_eq_s2)
{
	cr_assert_eq(0, ft_strncmp("test", "test", 4));
}

Test(ft_strncmp, test_s1_lt_s2)
{
	int	test = ft_strncmp("abcd", "bcde", 15);

	cr_assert_lt(test, 0);
}

Test(ft_strncmp, test_s1_gt_s2)
{
	int	test = ft_strncmp("bcde", "abcd", 15);

	cr_assert_gt(test, 0);
}
