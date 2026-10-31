/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 22:40:46 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/28 23:18:26 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <stddef.h>

Test(ft_lstadd_front, test_empty_list)
{
	t_list	*lst = NULL;
	char	*cnt = "omedeto shinji";
	t_list	em1 = {.next = NULL, .content = cnt};

	ft_lstadd_front(&lst, &em1);
	cr_assert_eq(lst, &em1);
}

Test(ft_lstadd_front, test_list)
{
	t_list	*lst;
	t_list	em1 = {.next = NULL, .content=NULL};
	t_list	em2 = {.next = NULL, .content=NULL};
	
	lst = &em1;
	ft_lstadd_front(&lst, &em2);
	cr_assert_eq(lst, &em2);
	cr_assert_eq(em2.next, &em1);
}
