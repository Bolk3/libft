/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 11:54:47 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/31 12:03:29 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>

Test(ft_memchr, test_segfault, .signal=11)
{
	char	*test = ft_memchr(NULL, 3, 13);
}

Test(ft_memchr, test_c_not_in_s_in_range)
{
	char	*str = "test";
	char	*test = ft_memchr(str, 's', 2);

	cr_assert_null(test);
}

Test(ft_memchr, test_c_in_s_in_range)
{
	char	*str = "test";
	char	*test = ft_memchr(str, 's', 3);

	cr_assert_not_null(test);
	cr_assert_eq(test, (str + 2));
}

Test(ft_memchr, test_c_in_s_not_in_range)
{
	char	*str = "abcde";
	char	*test = ft_memchr(str, 'd', 3);

	cr_assert_null(test);
}
