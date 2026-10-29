/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 10:51:55 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/29 12:29:06 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "wraps.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

static void	setup(void)
{
	should_malloc_fail = false;
}

static void	*manip(void *ptr)
{
	char	*cpy = strdup((char *)ptr);
	return (cpy);
}

TestSuite(ft_lstmap, .init=setup);

Test(ft_lstmap, test_malloc_fail)
{
	should_malloc_fail = true;

	char	*str = "def";
	t_list	em = {.next=NULL, .content=&str};
	t_list	*src = &em;
	t_list	*dsc = ft_lstmap(src, manip, free);

	cr_assert_null(dsc);
}

Test(ft_lstmap, test_empty_list)
{
	t_list	*src = NULL;
	t_list	*dst = ft_lstmap(src, manip, free);

	cr_assert_null(dst);
}

Test(ft_lstmap, test_list)
{
	char	*ctx1 = "ctx1";
	char	*ctx2 = "ctx2";
	t_list	em = {.next = NULL, .content=ctx1};
	t_list	em2 = {.next = &em, .content=ctx2};
	t_list	*src = &em2;
	t_list	*dst = ft_lstmap(src, manip, free);
	
	while (dst)
	{
		cr_assert_str_eq((char *)dst -> content, (char *)src -> content);
		dst = dst -> next;
		src = src -> next;
	}
}
