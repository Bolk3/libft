/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 13:54:14 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/30 14:08:19 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <stdlib.h>

Test(ft_atoi, test_segfault, .signal=11)
{
	ft_atoi(NULL);
}

Test(ft_atoi, test_huge_number_space_before_nbr)
{
	char	*str = "         42";
	int		test = ft_atoi(str);

	cr_assert_eq(test, atoi(str));
}

Test(ft_atoi, test_multiple_sign_should_return_zero)
{
	char	*str = "---124";
	int		test = ft_atoi(str);

	cr_assert_eq(test, atoi(str));
}

Test(ft_atoi, test_number_behind_non_numbers)
{
	char	*str = "134ab812";
	int		test = ft_atoi(str);

	cr_assert_eq(test, atoi(str));
}
