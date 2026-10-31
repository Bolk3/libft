/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 22:14:35 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/29 15:16:56 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "wraps.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <stddef.h>
#include <stdbool.h>

static void	teardown(void)
{
	should_malloc_fail = false;
}

TestSuite(ft_lstnew, .fini=teardown);

Test(ft_lstnew, test_malloc_fail)
{
	t_list	*test;
	char	*cnt = "omedeto shinji";

	should_malloc_fail = true;
	test = ft_lstnew(cnt);
	cr_assert_null(test);
}

Test(ft_lstnew, test_next_null)
{
	t_list	*test;

	test = ft_lstnew(NULL);
	cr_assert_null(test -> next);
}

Test(ft_lstnew, test_content_atributed)
{
	t_list	*test;
	char	*cnt = "omedeto shinji";

	test = ft_lstnew(cnt);
	cr_assert_eq(test -> content, cnt);
}
