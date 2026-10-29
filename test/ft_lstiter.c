/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 10:09:12 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/29 10:45:53 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>

void	manip(void *ptr)
{
	char	*str = (char *)ptr;

	for (int i = 0; str[i]; i++)
		str[i] = 'a';
}

Test(ft_lstiter, test_empty_list)
{
	t_list	*lst = NULL;

	ft_lstiter(lst, manip);
	cr_assert_null(lst);
}

Test(ft_lstiter, test_list)
{
	char	*ctx1 = "qwedd4sdfvce";
	char	*ctx2 = "ssdxxxxfrt";
	t_list	em = {.next=NULL, .content=ctx1};
	t_list	em1 = {.next=&em, .content=ctx2};
	t_list	*lst = &em1;

	ft_lstiter(lst, manip);
	for (int i = 0; ctx1[i]; i++) {
		cr_assert_eq(ctx1[i], 'a');
	}
	for (int i = 0; ctx2[i]; i++) {
		cr_assert_eq(ctx2[i], 'a');
	}
}
