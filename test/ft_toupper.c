/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 12:49:27 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/31 12:54:05 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <ctype.h>
#include <limits.h>

Test(ft_toupper, test_all_non_lowercase)
{
	for (int i = CHAR_MIN; i <= CHAR_MAX; i++) {
		if (!(i >= 'a' && i <= 'z'))
			cr_assert_eq(i , ft_toupper(i));
	}
}

Test(ft_toupper, test_all_lowercase)
{
	for (int i = 'a'; i <= 'z'; i++) {
		cr_assert_eq(toupper(i), ft_toupper(i));
	}
}
