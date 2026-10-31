/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 17:06:47 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/25 17:36:19 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <signal.h>
#include <criterion/criterion.h>
#include <criterion/assert.h>
#include <strings.h>

Test(ft_memmove, test_segfault_dest, .init=SIGSEGV)
{
	char	test[15];

	bzero(test, 15);
	ft_memmove(NULL, test, 15);
}

Test(ft_memmove, test_segfault_src, .init=SIGSEGV)
{
	char	test[15];

	bzero(test, 15);
	ft_memmove(test, NULL, 15);
}

Test(ft_memmove, test_non_overlaping_array)
{
	char	test[15];

	bzero(test, 15);
	ft_memmove(test, "testtesttesttt", 15);
	cr_assert_str_eq(test, "testtesttesttt");
}
