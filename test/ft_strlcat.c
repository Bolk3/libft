/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 14:14:25 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/31 15:34:25 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <string.h>

Test(ft_strlcat, test_segfault_dest, .signal=11)
{
	ft_strlcat(NULL, "test", 32);
}

Test(ft_strlcat, test_segfault_src, .signal=11)
{
	char	dst[4];
	ft_strlcat(dst, NULL, 4);
}

Test(ft_strlcat, test_src_lt_dst)
{
	char	*expected = "bonjour, au revoir";
	char	dst[50] = "bonjour";
	int		size = ft_strlcat(dst, ", au revoir", 50);

	cr_assert_eq(size, 18);
	cr_assert_str_eq(expected, dst);
	cr_assert_eq(0, dst[18]);
}

Test(ft_strlcat, test_tronc)
{
	char	test[13] = "omedeto, ";
	int		size = ft_strlcat(test, "shinji", 13);

	cr_assert_eq(size, 15);
	cr_assert_str_eq(test, "omedeto, shi");
}

Test(ft_strlcat, test_empty_src)
{
	char	test[15] = "omedeto, sh";
	char	*cpy = strdup(test);
	int		size = ft_strlcat(test, "", 15);

	cr_assert_eq(size, 11);
	cr_assert_str_eq(cpy, test);
}
