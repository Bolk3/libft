/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 22:51:57 by resonnet          #+#    #+#             */
/*   Updated: 2026/11/06 22:56:43 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <climits>
#include <gtest/gtest.h>

extern "C" {
#include <libft.h>
}

class	isalnum: public ::testing::Test {
	protected:
		bool	result;
		bool	expected;
};

TEST_F(isalnum, TestSignedNegChar)
{
	for (int i = CHAR_MIN; i < 0; i++) {
		result = ft_isalnum(i);
		expected = std::isalnum(i);
		ASSERT_EQ(result, expected);
	}
}

TEST_F(isalnum, TestSignedPosChar)
{
	for (int i = 0; i <= CHAR_MAX; i++) {
		result = ft_isalnum(i);
		expected = std::isalnum(i);
		ASSERT_EQ(result, expected);
	}
}
