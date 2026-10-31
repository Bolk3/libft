/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 12:19:41 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/31 12:34:44 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <string.h>

Test(ft_strrchr, test_segfault, .signal=11)
{
	ft_strrchr(NULL, 'q');
}

Test(ft_strrchr, test_c_not_in_s)
{
	char	*str = "radar";
	char	c = 'b';
	char	*test = ft_strrchr(str, c);

	cr_assert_null(test);
}

Test(ft_strrchr, test_c_in_s_same_as_strchr)
{
	char	*str = "radar";
	char	c = 'd';
	char	*test = ft_strrchr(str, c);

	cr_assert_not_null(test);
	cr_assert_eq(strrchr(str, c), test);
	cr_assert_eq(strchr(str, c), test);
}

Test(ft_strrchr, test_c_in_s_different_as_strchr)
{
	char	*str = "radar";
	char	c = 'r';
	char	*test = ft_strrchr(str, c);

	cr_assert_not_null(test);
	cr_assert_eq(strrchr(str, c), test);
	cr_assert_neq(strchr(str, c), test);
}

Test(ft_strrchr, test_c_is_null_char)
{
	char	*str = "radar";
	char	c = 0;
	char	*test = ft_strrchr(str, c);

	cr_assert_not_null(test);
	cr_assert_eq(strrchr(str, c), test);
	cr_assert_str_empty(test);
}
