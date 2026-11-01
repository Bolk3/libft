/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 12:36:49 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/30 13:25:05 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "wraps.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>

static void	manip(unsigned int i, char *str)
{
	str[i] = str[i] + 1;
}

Test(ft_striteri, test_segfault, .signal=11)
{
	ft_striteri(NULL, manip);
}

Test(ft_striteri, test_empty_str)
{
	char	test[] = "";
	ft_striteri(test, manip);

	cr_assert_not_null(test);
	cr_assert_str_empty(test);
}

Test(ft_striteri, test_str)
{
	char	test[] = "test";
	char	expected[] = "uftu";
	ft_striteri(test, manip);

	cr_assert_not_null(test);
	cr_assert_str_not_empty(test);
	cr_assert_str_eq(test, expected);
}
