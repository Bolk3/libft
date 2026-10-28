/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 17:37:46 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/27 18:08:27 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stddef.h>
#include <stdlib.h>

static char	*reverse_char(char *s, int n)
{
	size_t	i;
	char	tmp;

	i = 0;
	while (i < (n - 1) / 2)
	{
		tmp = s[i];
		s[i] = s[n - i - 1];
		s[n - i - 1] = tmp;
		i++;
	}
	return (s);
}

static int	get_number_size(int n)
{
	int	res;

	if (n == 0)
		return (1);
	if (n < 0)
		res = 1;
	else
		res = 0;
	while (n)
	{
		res++;
		n /= 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	i;
	int		f_neg;
	int		size;

	size = get_number_size(n) + 1;
	res = malloc(size);
	if (!res)
		return (NULL);
	i = 0;
	if (n < 0)
		f_neg = 1;
	else
		f_neg = 0;
	while (n)
	{
		res[i++] = n % 10;
		n /= 10;
	}
	if (f_neg)
		res[i++] = '-';
	res[i] = 0;
	return (reverse_char(res, size));
}
