/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 22:42:36 by resonnet          #+#    #+#             */
/*   Updated: 2026/11/03 14:28:49 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	if (!*lst)
		return ;
	current = *lst;
	next = current -> next;
	while (current -> next)
	{
		ft_lstdelone(current, del);
		current = next;
		next = current -> next;
	}
	ft_lstdelone(current, del);
	*lst = NULL;
}
