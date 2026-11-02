/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 21:46:57 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/24 21:58:26 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/internal/test.h>
#include <libft.h>
#include <criterion/assert.h>
#include <criterion/internal/assert.h>
#include <ctype.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

Test(ft_isascii, test_rand_pos_int)
{
	int	value;

	for (int i = 0;	i <= 10; i++) {
		srand(time(NULL));
		value = rand() % 10000;
		cr_assert_eq(ft_isascii(value), isascii(value));
	}
}

Test(ft_isascii, test_rand_neg_int)
{
	int	value;

	for (int i = 0; i <= 10; i++) {
		srand(time(NULL));
		value = rand() % 10000;
		value *= -1;
		cr_assert_eq(ft_isascii(value), isascii(value));
	}
}
