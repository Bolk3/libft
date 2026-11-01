/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 11:06:38 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/25 11:12:25 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <criterion/assert.h>
#include <criterion/internal/assert.h>
#include <signal.h>
#include <criterion/criterion.h>
#include <strings.h>

Test(ft_memset, test_segfault, .signal=SIGSEGV)
{
	ft_memset(NULL, 'a', 14);
}

Test(ft_memset, test_array_when_size_lt_array_size)
{
	char	test[15];

	bzero(test, 15);
	ft_memset(test, 5, 6);
	for (int i = 0; i < 15; i++) {
		if (i < 6)
			cr_assert_eq(test[i], 5);
		else
			cr_assert_eq(test[i], 0);
	}
}

Test(ft_memset, test_array_when_size_equal_array_size)
{
	char	test[15];

	bzero(test, 15);
	ft_memset(test, 5, 15);
	for (int i = 0; i < 15; i++)
		cr_assert_eq(test[i], 5);
}

Test(ft_memset, test_return_pointers)
{
	char	test[15];

	bzero(test, 15);
	cr_assert_eq(test, ft_memset(test, 5, 15));
}
