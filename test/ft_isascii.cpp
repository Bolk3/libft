/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 22:58:18 by resonnet          #+#    #+#             */
/*   Updated: 2026/11/06 23:03:57 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <climits>
#include <gtest/gtest.h>

extern "C" {
#include <libft.h>
}

class	isascii: public ::testing::Test {
	protected:
		bool	result;
		bool	expected;
};

TEST_F(isascii, TestSignedNegChar)
{
	for (int i = CHAR_MIN; i < 0; i++) {
		result = ft_isascii(i);
		expected = isascii(i);
		ASSERT_EQ(result, expected);
	}
}

TEST_F(isascii, TestSignedPosChar)
{
	for (int i = 0; i <= CHAR_MAX; i++) {
		result = ft_isascii(i);
		expected = isascii(i);
		ASSERT_EQ(result, expected);
	}
}
