/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 12:39:31 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/31 12:53:12 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <ctype.h>
#include <limits.h>

Test(ft_tolower, test_all_non_uppercase)
{
	for (int i = CHAR_MIN; i <= CHAR_MAX; i++) {
		if (!(i >= 'A' && i <= 'Z'))
			cr_assert_eq(i, ft_tolower(i));
	}
}

Test(ft_tolower, test_all_uppercase)
{
	for (int i = 'A'; i <= 'Z'; i++) {
		cr_assert_eq(tolower(i), ft_tolower(i));
	}
}
