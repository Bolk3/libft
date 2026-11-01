/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 22:31:07 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/27 22:32:46 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		res;
	t_list	*current;

	res = 0;
	current = lst;
	while (current)
	{
		res++;
		current = current -> next;
	}
	return (res);
}
