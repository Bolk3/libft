/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 23:20:01 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/28 23:23:01 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>

Test(ft_lstsize, test_empty_list)
{
	t_list	*test = NULL;
	cr_assert_eq(ft_lstsize(test), 0);
}

Test(ft_lstsize, test_size_one_list)
{
	t_list	em = {.next = NULL};
	t_list	*lst = &em;

	cr_assert_eq(ft_lstsize(lst), 1);
}

Test(ft_lstsize, test_size_five_list)
{
	t_list	em1 = {.next=NULL};
	t_list	em2 = {.next=&em1};
	t_list	em3 = {.next=&em2};
	t_list	em4 = {.next=&em3};
	t_list	em5 = {.next=&em4};
	t_list	*lst = &em5;

	cr_assert_eq(ft_lstsize(lst), 5);
}
