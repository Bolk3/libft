/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 12:31:39 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/25 17:01:14 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <criterion/logging.h>
#include <strings.h>
#include <signal.h>
#include <criterion/criterion.h>
#include <criterion/assert.h>

Test(ft_memcpy, test_segfault_dest, .signal=SIGSEGV)
{
	char	test[15] = "test";
	ft_memcpy(NULL, test, 15);
}

Test(ft_memcpy, test_segfault_src, .signal=SIGSEGV)
{
	char	test[15] = "test";
	ft_memcpy(test, NULL, 15);
}

Test(ft_memcpy, test_non_overlaping_array)
{
	char	dest[15];
	char	src[] = "omedeto shinji!";

	ft_memcpy(dest, src, 15);
	for (int i = 0; i < 15; i++) {
		cr_log_info("%c, %c", dest[i], src[i]);
		cr_assert_eq(dest[i], src[i]);
	}
}
