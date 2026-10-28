/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 22:54:50 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/27 22:57:59 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stddef.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*current;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	current = lst;
	res = NULL;
	while (current)
	{
		tmp = ft_lstnew(f(current -> content));
		if (!tmp)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		if (ft_lstsize(res) == 0)
			res = tmp;
		else
			ft_lstadd_back(&res, tmp);
		current = current -> next;
	}
	return (res);
}
