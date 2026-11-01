/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 16:01:19 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/29 16:09:44 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "wraps.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <string.h>

Test(ft_strchr, test_segfault, .signal=11)
{
	ft_strchr(NULL, 4);
}

Test(ft_strchr, test_find_char)
{
	char	*string = "omdedeto, shinji";
	cr_assert_eq(ft_strchr(string, 'e'), strchr(string, 'e'));
}

Test(ft_strchr, test_not_find_char)
{
	char	*string = "omedeto, shinji";
	cr_assert_null(ft_strchr(string, 'a'));
}
