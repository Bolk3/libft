/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 12:04:34 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/25 12:26:36 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <string.h>
#include <strings.h>
#include <signal.h>
#include <criterion/criterion.h>

Test(ft_bzero, test_segfault, .signal=SIGSEGV)
{
	ft_bzero(NULL, 15);
}

Test(ft_bzero, test_array_when_size_lt_array_size)
{
	char	test[15];

	memset(test, 5, 15);
	ft_bzero(test, 5);
	for (int i = 0; i < 15; i++) {
		if (i < 5)
			cr_assert_eq(test[i], 0);
		else
			cr_assert_eq(test[i], 5);
	}
}

Test(ft_bzero, test_array_when_size_equals_array_size)
{
	char	test[15];

	memset(test, 5, 15);
	ft_bzero(test, 15);
	for (int i = 0; i < 15; i++)
		cr_assert_eq(test[i], 0);
}
