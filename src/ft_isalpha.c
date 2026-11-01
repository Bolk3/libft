/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 16:20:10 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/24 16:21:21 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

static int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

int	ft_isalpha(int c)
{
	return (ft_islower(c) || ft_isupper(c));
}
