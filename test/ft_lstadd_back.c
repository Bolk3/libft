/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 00:07:46 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/29 00:37:58 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>

Test(ft_lstadd_back, test_empty_list)
{
	t_list	*lst = NULL;
	t_list	em = {.next = NULL};

	ft_lstadd_back(&lst, &em);
	cr_assert_eq(lst, &em);
}

Test(ft_lstadd_back, test_size_one_list)
{
	t_list	em = {.next = NULL};
	t_list	em1 = {.next = NULL};
	t_list	*lst = &em;

	ft_lstadd_back(&lst, &em1);
	cr_assert_eq(em.next, &em1);
}

Test(ft_lstadd_back, test_list)
{
	t_list	em = {.next=NULL};
	t_list	em1 = {.next=&em};
	t_list	test = {.next=NULL};
	t_list	*lst = &em1;

	ft_lstadd_back(&lst, &test);
	cr_assert_eq(em.next, &test);
}
