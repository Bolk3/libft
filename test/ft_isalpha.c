/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 21:00:24 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/24 21:35:27 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <criterion/criterion.h>
#include <criterion/assert.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <limits.h>
#include <ctype.h>

Test(ft_isalpha, test_all_char_range)
{
	for (int i = CHAR_MIN; i <= CHAR_MAX; i++) {
		cr_assert_eq(ft_isalpha(i) != 0, isalpha(i) != 0);
	}
}
