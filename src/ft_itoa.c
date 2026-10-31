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
#include <stdint.h>
#include <stdlib.h>

static char	*reverse_arr_str(char *str, int size, int offset)
{
	int		i;
	char	tmp;

	i = 0;
	while (i < size / 2)
	{
		tmp = str[i];
		str[i] = str[size - i - 1];
		str[size - i - 1] = tmp;
		i++;
	}
	return (str - offset);
}

static int	get_str_size(int n)
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
	int		size;
	int		i;
	long	nb;

	nb = n;
	i = 0;
	size = get_str_size(n);
	res = malloc(size + 1);
	if (!res)
		return (NULL);
	if (n < 0)
	{
		res[i++] = '-';
		nb *= -1;
	}
	while (i < size)
	{
		res[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	res[i] = 0;
	if (n < 0)
		return (reverse_arr_str(res + 1, size - 1, 1));
	return (reverse_arr_str(res, size, 0));
}
