/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 00:39:01 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/29 12:41:26 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "wraps.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <criterion/logging.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

t_list	*lst;

void	teardown(void)
{
	free(lst);
}

Test(ft_lstdelone, test_empty_node_deletion)
{
	lst = NULL;
	ft_lstdelone(lst, free);
	cr_assert_null(lst);
}

Test(ft_lstdelone, test_connected_node_deletion, .fini=teardown)
{
	t_list	*test;

	lst = __real_malloc(sizeof(t_list));
	test = __real_malloc(sizeof(t_list));
	if (!lst || !test)
	{
		free(test);
		cr_assert(false, "cannot malloc");
	}
	lst -> next = NULL;
	lst -> content = NULL;
	test -> next = lst;
	test -> content = NULL;
	ft_lstdelone(test, free);
	cr_assert_not_null(lst);
}
