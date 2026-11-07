/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 21:38:08 by resonnet          #+#    #+#             */
/*   Updated: 2026/11/05 21:47:51 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <climits>
#include <gtest/gtest.h>

extern "C" {
#include <libft.h>
}

class	isalpha: public ::testing::Test {
	protected:
		bool	result;
		bool	expected;
};

TEST_F(isalpha, TestSignedNegChar)
{
	for (int i = CHAR_MIN; i < 0; i++) {
		result = ft_isalpha(i);
		expected = std::isalpha(i);
		ASSERT_EQ(result, expected);
	}
}

TEST_F(isalpha, TestSignedPosChar)
{
	for (int i = 0; i <= CHAR_MAX; i++) {
		result = ft_isalpha(i);
		expected = std::isalpha(i);
		ASSERT_EQ(result, expected);
	}
}
