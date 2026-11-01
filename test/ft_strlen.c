/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 22:10:56 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/24 22:35:25 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <criterion/assert.h>
#include <signal.h>
#include <string.h>
#include <stddef.h>
#include <criterion/criterion.h>

Test(ft_strlen, test_segfault, .signal=SIGSEGV)
{
	ft_strlen(NULL);
}

Test(ft_strlen, test_return_when_null_inbetween)
{
	char	a[] = {'b', 'e', 'l', 'l', 0, 'e', ' '};
	cr_assert_eq(ft_strlen(a), strlen(a));
}

Test(ft_strlen, test_normal_string_0)
{
	char	a[] = "asdcxc0091239841\t..,,.;/,kl;;..\\,,.l,mmasmdwjasdmm\nnannsda";

	cr_assert_eq(ft_strlen(a), strlen(a));
}
