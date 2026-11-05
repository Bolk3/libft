/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 20:10:54 by resonnet          #+#    #+#             */
/*   Updated: 2026/11/05 20:14:25 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern "C"
{
# include <libft.h>
}

#include "checks.hpp"
#include <gtest/gtest.h>

TEST(FtSplit, returnNullAtFirstMallocFail)
{
	char	**res;

	malloc_fail_at = 1;
	res = ft_split("testing phase", ' ');
	if (!res && leakCheck())
		SUCCEED();
}
