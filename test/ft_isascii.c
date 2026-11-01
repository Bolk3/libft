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

#include <libft.h>
#include <criterion/assert.h>
#include <criterion/internal/assert.h>
#include <ctype.h>
#include <limits.h>
#include <criterion/criterion.h>
#include <stdlib.h>
#include <time.h>

Test(ft_isascii, test_random_int)
{
	int	value;
	srand(time(NULL));

	for (int i = 0;	i <= 10; i++) {
		value = rand() % 10000;
		cr_assert_eq(ft_isascii(value) != 0, isascii(value) != 0);
	}
}
