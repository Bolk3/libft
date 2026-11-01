/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 23:58:57 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/29 00:58:44 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>


Test(ft_lstlast, test_empty_list_should_return_null)
{
	t_list	*lst = NULL;
	t_list	*last = ft_lstlast(lst);

	cr_assert_null(last);
}

Test(ft_lstlast, test_size_one_list_should_return_self)
{
	t_list	em = {.next=NULL};
	t_list	*lst = &em;
	t_list	*last = ft_lstlast(lst);

	cr_assert_eq(last, &em);
}

Test(ft_lstlast, test_list)
{
	t_list	em = {.next=NULL};
	t_list	em1 = {.next=&em};
	t_list	*lst = &em1;
	t_list	*last = ft_lstlast(lst);

	cr_assert_eq(last, &em);
}
