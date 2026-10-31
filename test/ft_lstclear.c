/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 09:39:46 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/29 10:06:25 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/libft.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

void	*__real_malloc(size_t size);

Test(ft_lstclear, test_empty_list)
{
	t_list	*lst = NULL;

	ft_lstclear(&lst, free);
	cr_assert_null(lst);
}

Test(ft_lstclear, test_list)
{
	t_list	*em0 = __real_malloc(sizeof(t_list));
	t_list	*em1 = __real_malloc(sizeof(t_list));
	t_list	*lst;

	if (!em0)
	{
		if (em1)
			free(em1);
		cr_assert(false, "cannot malloc");
	}
	if (!em1)
	{
		if (em0)
			free(em0);
		cr_assert(false, "cannot malloc");
	}
	lst = em1;
	em1 -> next = em0;
	em1 -> content = NULL;
	em0 -> next = NULL;
	em0 -> content = NULL;
	ft_lstclear(&lst, free);
	cr_assert_null(lst);
}
