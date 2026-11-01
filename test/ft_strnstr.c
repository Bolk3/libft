/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 14:09:35 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/30 14:16:39 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <string.h>

Test(ft_strnstr, test_segfault_big, .signal=11)
{
	ft_strnstr(NULL, "fd", 14);
}

Test(ft_strnstr, test_segfault_little, .signal=11)
{
	ft_strnstr("armure terminator", NULL, 14);
}

Test(ft_strnstr, test_little_not_in_big_full_size)
{
	char	*big = "10:15 Saturday Night";
	char	*little = "zambla";
	char	*test = ft_strnstr(big, little, strlen(big));

	cr_assert_null(test);
}

Test(ft_strnstr, test_little_present_futher_than_search)
{
	char	*big = "10:15 Saturday Night";
	char	*little = "Night";
	char	*test = ft_strnstr(big, little, 6);

	cr_assert_null(test);
}

Test(ft_strnstr, test_little_present_in_range)
{
	char	*big = "10:15 Saturday Night";
	char	*little = "10:15";
	char	*test = ft_strnstr(big, little, strlen(big));

	cr_assert_not_null(test);
	cr_assert_eq(test, big);
}

Test(ft_strnstr, test_empty_little_should_return_big)
{
	char	*big = "10:15 Saturday Night";
	char	*little = "";
	char	*test = ft_strnstr(big, little, strlen(big));

	cr_assert_not_null(test);
	cr_assert_eq(test, big);
}
